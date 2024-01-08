#pragma once

#include "Shader.h"
#include "utils/DoubleLinkedList.h"
#include "Mesh.h"
#include "Logger.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb_image.h>
#include <vector>

namespace KineZ {
	class Model
	{
	private:
		std::vector<Texture> textures_loaded;
		std::vector<Mesh> meshes;
		std::string directory;
	public:
		Model(std::string path);
		
		void Render(const Shader& shader);
		static void AddModel(Model* model);
	private:
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> LoadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName);
		unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
	};
}

