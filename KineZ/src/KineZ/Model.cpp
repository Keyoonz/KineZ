#include "Model.h"

#include "utils/DoubleLinkedList.h"
KineZ::DoubleLinkedList<KineZ::Model*> k_models;

KineZ::Model::Model(std::string path)
{
	extern Logger KZlogger;
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		KZlogger.Error(importer.GetErrorString());
	}
	directory = path.substr(0, path.find_last_of('/'));

	ProcessNode(scene->mRootNode, scene);
}

void KineZ::Model::Render(const Shader& shader)
{
	for (int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Render(shader);
	}
}


void KineZ::Model::AddModel(Model* model)
{
	k_models.push_back(model);
}

void KineZ::Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(ProcessMesh(mesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

KineZ::Mesh KineZ::Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Mesh::Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	extern Logger KZlogger;
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Mesh::Vertex vertex;
		glm::vec3 placeholder;
		placeholder.x = mesh->mVertices[i].x;
		placeholder.y = mesh->mVertices[i].y;
		placeholder.z = mesh->mVertices[i].z;
		vertex.position = placeholder;

		if (mesh->HasNormals())
		{
			placeholder.x = mesh->mNormals[i].x;
			placeholder.y = mesh->mNormals[i].y;
			placeholder.z = mesh->mNormals[i].z;
			vertex.normal = placeholder;
		}

		if (mesh->HasTextureCoords(0))
		{
			glm::vec2 placeholder;

			placeholder.x = mesh->mTextureCoords[0][i].x;
			placeholder.x = mesh->mTextureCoords[0][i].y;
			vertex.textureCoordinates = placeholder;
		}
		else
		{
			vertex.textureCoordinates = glm::vec2(0.0f, 0.0f);
		}
		
		vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	
	std::vector<Texture> diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

	std::vector<Texture> specularMaps = LoadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	
	std::vector<Texture> normalMaps = LoadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
	textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	
	std::vector<Texture> heightMaps = LoadMaterialTextures(material, aiTextureType_AMBIENT, "texture_ambient");
	textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

	return Mesh(vertices, indices, textures);
}

std::vector<KineZ::Texture> KineZ::Model::LoadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName)
{
	std::vector<Texture> textures;
	for (unsigned int i = 0; i < material->GetTextureCount(type); i++)
	{
		aiString str;
		material->GetTexture(type, i, &str);

		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			Texture texture;
			texture.id = TextureFromFile(str.C_Str(), this->directory);
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			textures_loaded.push_back(texture);
		}
	}
	return textures;
}

unsigned int KineZ::Model::TextureFromFile(const char* path, const std::string& directory, bool gamma)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		extern KineZ::Logger KZlogger;
		KZlogger.Error(std::string("Texture failed to load at path: ") + std::string(path));
		stbi_image_free(data);
	}

	return textureID;
}

