// Copyright (c) 2015-2016 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "source/spirv_target_env.h"

#include <cstring>
#include <string>

#include "source/spirv_constant.h"
#include "spirv-tools/libspirv.h"

const char* spvTargetEnvDescription(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
      return "SPIR-V 1.0";
    case SPV_ENV_VULKAN_1_0:
      return "SPIR-V 1.0 (under Vulkan 1.0 semantics)";
    case SPV_ENV_UNIVERSAL_1_1:
      return "SPIR-V 1.1";
    case SPV_ENV_OPENCL_1_2:
      return "SPIR-V 1.0 (under OpenCL 1.2 Full Profile semantics)";
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
      return "SPIR-V 1.0 (under OpenCL 1.2 Embedded Profile semantics)";
    case SPV_ENV_OPENCL_2_0:
      return "SPIR-V 1.0 (under OpenCL 2.0 Full Profile semantics)";
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
      return "SPIR-V 1.0 (under OpenCL 2.0 Embedded Profile semantics)";
    case SPV_ENV_OPENCL_2_1:
      return "SPIR-V 1.0 (under OpenCL 2.1 Full Profile semantics)";
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
      return "SPIR-V 1.0 (under OpenCL 2.1 Embedded Profile semantics)";
    case SPV_ENV_OPENCL_2_2:
      return "SPIR-V 1.2 (under OpenCL 2.2 Full Profile semantics)";
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
      return "SPIR-V 1.2 (under OpenCL 2.2 Embedded Profile semantics)";
    case SPV_ENV_OPENGL_4_0:
      return "SPIR-V 1.0 (under OpenGL 4.0 semantics)";
    case SPV_ENV_OPENGL_4_1:
      return "SPIR-V 1.0 (under OpenGL 4.1 semantics)";
    case SPV_ENV_OPENGL_4_2:
      return "SPIR-V 1.0 (under OpenGL 4.2 semantics)";
    case SPV_ENV_OPENGL_4_3:
      return "SPIR-V 1.0 (under OpenGL 4.3 semantics)";
    case SPV_ENV_OPENGL_4_5:
      return "SPIR-V 1.0 (under OpenGL 4.5 semantics)";
    case SPV_ENV_UNIVERSAL_1_2:
      return "SPIR-V 1.2";
    case SPV_ENV_UNIVERSAL_1_3:
      return "SPIR-V 1.3";
    case SPV_ENV_VULKAN_1_1:
      return "SPIR-V 1.3 (under Vulkan 1.1 semantics)";
    case SPV_ENV_WEBGPU_0:
      return "SPIR-V 1.3 (under WIP WebGPU semantics)";
    case SPV_ENV_UNIVERSAL_1_4:
      return "SPIR-V 1.4";
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
      return "SPIR-V 1.4 (under Vulkan 1.1 semantics)";
    case SPV_ENV_UNIVERSAL_1_5:
      return "SPIR-V 1.5";
    case SPV_ENV_VULKAN_1_2:
      return "SPIR-V 1.5 (under Vulkan 1.2 semantics)";
  }
  return "";
}

uint32_t spvVersionForTargetEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5:
      return SPV_SPIRV_VERSION_WORD(1, 0);
    case SPV_ENV_UNIVERSAL_1_1:
      return SPV_SPIRV_VERSION_WORD(1, 1);
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_OPENCL_2_2:
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
      return SPV_SPIRV_VERSION_WORD(1, 2);
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_WEBGPU_0:
      return SPV_SPIRV_VERSION_WORD(1, 3);
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
      return SPV_SPIRV_VERSION_WORD(1, 4);
    case SPV_ENV_UNIVERSAL_1_5:
    case SPV_ENV_VULKAN_1_2:
      return SPV_SPIRV_VERSION_WORD(1, 5);
  }
  return SPV_SPIRV_VERSION_WORD(0, 0);
}

static const std::pair<const char*, spv_target_env> spvTargetEnvNameMap[] = {
    {"vulkan1.1spv1.4", SPV_ENV_VULKAN_1_1_SPIRV_1_4},
    {"vulkan1.0", SPV_ENV_VULKAN_1_0},
    {"vulkan1.1", SPV_ENV_VULKAN_1_1},
    {"vulkan1.2", SPV_ENV_VULKAN_1_2},
    {"spv1.0", SPV_ENV_UNIVERSAL_1_0},
    {"spv1.1", SPV_ENV_UNIVERSAL_1_1},
    {"spv1.2", SPV_ENV_UNIVERSAL_1_2},
    {"spv1.3", SPV_ENV_UNIVERSAL_1_3},
    {"spv1.4", SPV_ENV_UNIVERSAL_1_4},
    {"spv1.5", SPV_ENV_UNIVERSAL_1_5},
    {"opencl1.2embedded", SPV_ENV_OPENCL_EMBEDDED_1_2},
    {"opencl1.2", SPV_ENV_OPENCL_1_2},
    {"opencl2.0embedded", SPV_ENV_OPENCL_EMBEDDED_2_0},
    {"opencl2.0", SPV_ENV_OPENCL_2_0},
    {"opencl2.1embedded", SPV_ENV_OPENCL_EMBEDDED_2_1},
    {"opencl2.1", SPV_ENV_OPENCL_2_1},
    {"opencl2.2embedded", SPV_ENV_OPENCL_EMBEDDED_2_2},
    {"opencl2.2", SPV_ENV_OPENCL_2_2},
    {"opengl4.0", SPV_ENV_OPENGL_4_0},
    {"opengl4.1", SPV_ENV_OPENGL_4_1},
    {"opengl4.2", SPV_ENV_OPENGL_4_2},
    {"opengl4.3", SPV_ENV_OPENGL_4_3},
    {"opengl4.5", SPV_ENV_OPENGL_4_5},
    {"webgpu0", SPV_ENV_WEBGPU_0},
};

bool spvParseTargetEnv(const char* s, spv_target_env* env) {
  auto match = [s](const char* b) {
    return s && (0 == strncmp(s, b, strlen(b)));
  };
  for (auto& name_env : spvTargetEnvNameMap) {
    if (match(name_env.first)) {
      if (env) {
        *env = name_env.second;
      }
      return true;
    }
  }
  if (env) *env = SPV_ENV_UNIVERSAL_1_0;
  return false;
}

bool spvIsVulkanEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5:
    case SPV_ENV_UNIVERSAL_1_1:
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_OPENCL_2_2:
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_WEBGPU_0:
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_UNIVERSAL_1_5:
      return false;
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
    case SPV_ENV_VULKAN_1_2:
      return true;
  }
  return false;
}

bool spvIsOpenCLEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_UNIVERSAL_1_1:
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5:
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_WEBGPU_0:
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
    case SPV_ENV_UNIVERSAL_1_5:
    case SPV_ENV_VULKAN_1_2:
      return false;
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_2_2:
      return true;
  }
  return false;
}

bool spvIsWebGPUEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_UNIVERSAL_1_1:
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5:
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_2_2:
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
    case SPV_ENV_UNIVERSAL_1_5:
    case SPV_ENV_VULKAN_1_2:
      return false;
    case SPV_ENV_WEBGPU_0:
      return true;
  }
  return false;
}

bool spvIsOpenGLEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_UNIVERSAL_1_1:
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_2:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_2_2:
    case SPV_ENV_WEBGPU_0:
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4:
    case SPV_ENV_UNIVERSAL_1_5:
    case SPV_ENV_VULKAN_1_2:
      return false;
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5:
      return true;
  }
  return false;
}

bool spvIsVulkanOrWebGPUEnv(spv_target_env env) {
  return spvIsVulkanEnv(env) || spvIsWebGPUEnv(env);
}

std::string spvLogStringForEnv(spv_target_env env) {
  switch (env) {
    case SPV_ENV_OPENCL_1_2:
    case SPV_ENV_OPENCL_2_0:
    case SPV_ENV_OPENCL_2_1:
    case SPV_ENV_OPENCL_2_2:
    case SPV_ENV_OPENCL_EMBEDDED_1_2:
    case SPV_ENV_OPENCL_EMBEDDED_2_0:
    case SPV_ENV_OPENCL_EMBEDDED_2_1:
    case SPV_ENV_OPENCL_EMBEDDED_2_2: {
      return "OpenCL";
    }
    case SPV_ENV_OPENGL_4_0:
    case SPV_ENV_OPENGL_4_1:
    case SPV_ENV_OPENGL_4_2:
    case SPV_ENV_OPENGL_4_3:
    case SPV_ENV_OPENGL_4_5: {
      return "OpenGL";
    }
    case SPV_ENV_VULKAN_1_0:
    case SPV_ENV_VULKAN_1_1:
    case SPV_ENV_VULKAN_1_1_SPIRV_1_4: {
      case SPV_ENV_VULKAN_1_2:
        return "Vulkan";
    }
    case SPV_ENV_WEBGPU_0: {
      return "WebGPU";
    }
    case SPV_ENV_UNIVERSAL_1_0:
    case SPV_ENV_UNIVERSAL_1_1:
    case SPV_ENV_UNIVERSAL_1_2:
    case SPV_ENV_UNIVERSAL_1_3:
    case SPV_ENV_UNIVERSAL_1_4:
    case SPV_ENV_UNIVERSAL_1_5: {
      return "Universal";
    }
  }
  return "Unknown";
}

std::string spvTargetEnvList(const int pad, const int wrap) {
  std::string ret;
  size_t max_line_len = wrap - pad;  // The first line isn't padded
  std::string line;
  std::string sep = "";

  for (auto& name_env : spvTargetEnvNameMap) {
    std::string word = sep + name_env.first;
    if (line.length() + word.length() > max_line_len) {
      // Adding one word wouldn't fit, commit the line in progress and
      // start a new one.
      ret += line + "\n";
      line.assign(pad, ' ');
      // The first line is done. The max length now comprises the
      // padding.
      max_line_len = wrap;
    }
    line += word;
    sep = "|";
  }

  ret += line;

  return ret;
}
