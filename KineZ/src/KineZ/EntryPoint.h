#pragma once

#include "Application.h"

extern KineZ::Application *KineZ::CreateApplication();
extern KineZ::ShaderPaths KineZ::SetShaderPaths();
extern void KineZ::CreateMeshes();

int main() {
  KineZ::Application *app = KineZ::CreateApplication();
  app->ImplementMeshes = KineZ::CreateMeshes;
  app->shaderPaths = KineZ::SetShaderPaths();
  app->Run();
  delete app;
}
