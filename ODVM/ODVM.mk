##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ODVM
ConfigurationName      :=Debug
WorkspacePath          :=/home/sfulham/dev/ODVMEngine
ProjectPath            :=/home/sfulham/dev/ODVMEngine/ODVM
IntermediateDirectory  :=../bin-int/Debug-linux-x86_64/ODVM
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Shaun Fulham
Date                   :=31/03/20
CodeLitePath           :=/home/sfulham/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/Debug-linux-x86_64/ODVM/libODVM.a
Preprocessors          :=$(PreprocessorSwitch)GLFW_INCLUDE_NONE $(PreprocessorSwitch)_GLFW_X11 $(PreprocessorSwitch)ODVM_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ODVM.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -m64 libs/GLFW/bin/Debug-linux-x86_64/GLFW/libGLFW.a libs/Glad/bin/Debug-linux-x86_64/Glad/libGlad.a libs/ImGui/bin/Debug-linux-x86_64/ImGui/libImGui.a libs/Discord/bin/Debug-linux-x86_64/Discord/libDiscord.a -lopengl32.lib -ldl -lm -lX11 -lXinerama -lXi -lXcursor -lpthread -lXrandr -lrt
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)src $(IncludeSwitch)libs/spdlog/include $(IncludeSwitch)libs/GLFW/include $(IncludeSwitch)libs/Glad/include $(IncludeSwitch)libs/ImGui $(IncludeSwitch)libs/glm $(IncludeSwitch)libs/stb $(IncludeSwitch)libs/discord/cpp $(IncludeSwitch)libs/Vulkan/latest/Include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -m64 -g -std=c++17 $(Preprocessors)
CFLAGS   :=  -m64 -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_odvmpch.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(ObjectSuffix) 

Objects2=$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(ObjectSuffix) 

Objects3=$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/libs_stb_stb_image.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(ObjectSuffix) 

Objects4=$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) $(Objects2) $(Objects3) $(Objects4) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	@echo $(Objects2) >> $(ObjectsFileList)
	@echo $(Objects3) >> $(ObjectsFileList)
	@echo $(Objects4) >> $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "/home/sfulham/dev/ODVMEngine/.build-debug"
	@echo rebuilt > "/home/sfulham/dev/ODVMEngine/.build-debug/ODVM"

MakeIntermediateDirs:
	@test -d ../bin-int/Debug-linux-x86_64/ODVM || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/ODVM


../bin-int/Debug-linux-x86_64/ODVM:
	@test -d ../bin-int/Debug-linux-x86_64/ODVM || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/ODVM

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLRendererAPI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLRendererAPI.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLRendererAPI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLRendererAPI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLRendererAPI.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLRendererAPI.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(ObjectSuffix): src/ODVM/Renderer/Shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(DependSuffix) -MM src/ODVM/Renderer/Shader.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(PreprocessSuffix): src/ODVM/Renderer/Shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Shader.cpp$(PreprocessSuffix) src/ODVM/Renderer/Shader.cpp

$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLVertexArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLVertexArray.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLVertexArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLVertexArray.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLVertexArray.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLVertexArray.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(ObjectSuffix): src/ODVM/Renderer/Buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(DependSuffix) -MM src/ODVM/Renderer/Buffer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(PreprocessSuffix): src/ODVM/Renderer/Buffer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Buffer.cpp$(PreprocessSuffix) src/ODVM/Renderer/Buffer.cpp

$(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(ObjectSuffix): src/ODVM/Core/Layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(DependSuffix) -MM src/ODVM/Core/Layer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Core/Layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(PreprocessSuffix): src/ODVM/Core/Layer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Core_Layer.cpp$(PreprocessSuffix) src/ODVM/Core/Layer.cpp

$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(ObjectSuffix): src/ODVM/CameraControllers/CameraControllers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(DependSuffix) -MM src/ODVM/CameraControllers/CameraControllers.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/CameraControllers/CameraControllers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(PreprocessSuffix): src/ODVM/CameraControllers/CameraControllers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_CameraControllers_CameraControllers.cpp$(PreprocessSuffix) src/ODVM/CameraControllers/CameraControllers.cpp

$(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(ObjectSuffix): src/ODVM/Core/Log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(DependSuffix) -MM src/ODVM/Core/Log.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Core/Log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(PreprocessSuffix): src/ODVM/Core/Log.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Core_Log.cpp$(PreprocessSuffix) src/ODVM/Core/Log.cpp

$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(ObjectSuffix): src/ODVM/ImGui/ImGuiBuild.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(DependSuffix) -MM src/ODVM/ImGui/ImGuiBuild.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/ImGui/ImGuiBuild.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(PreprocessSuffix): src/ODVM/ImGui/ImGuiBuild.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_ImGui_ImGuiBuild.cpp$(PreprocessSuffix) src/ODVM/ImGui/ImGuiBuild.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(ObjectSuffix): src/ODVM/Renderer/Cameras.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(DependSuffix) -MM src/ODVM/Renderer/Cameras.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Cameras.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(PreprocessSuffix): src/ODVM/Renderer/Cameras.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Cameras.cpp$(PreprocessSuffix) src/ODVM/Renderer/Cameras.cpp

$(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(ObjectSuffix): src/ODVM/Core/Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(DependSuffix) -MM src/ODVM/Core/Application.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Core/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(PreprocessSuffix): src/ODVM/Core/Application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Core_Application.cpp$(PreprocessSuffix) src/ODVM/Core/Application.cpp

$(IntermediateDirectory)/src_odvmpch.cpp$(ObjectSuffix): src/odvmpch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_odvmpch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_odvmpch.cpp$(DependSuffix) -MM src/odvmpch.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/odvmpch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_odvmpch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_odvmpch.cpp$(PreprocessSuffix): src/odvmpch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_odvmpch.cpp$(PreprocessSuffix) src/odvmpch.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(ObjectSuffix): src/ODVM/Renderer/Texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(DependSuffix) -MM src/ODVM/Renderer/Texture.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(PreprocessSuffix): src/ODVM/Renderer/Texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Texture.cpp$(PreprocessSuffix) src/ODVM/Renderer/Texture.cpp

$(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(ObjectSuffix): src/Platform/Windows/WindowsInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(DependSuffix) -MM src/Platform/Windows/WindowsInput.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/Windows/WindowsInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(PreprocessSuffix): src/Platform/Windows/WindowsInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_Windows_WindowsInput.cpp$(PreprocessSuffix) src/Platform/Windows/WindowsInput.cpp

$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(ObjectSuffix): src/ODVM/ImGui/ImGuiLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(DependSuffix) -MM src/ODVM/ImGui/ImGuiLayer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/ImGui/ImGuiLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(PreprocessSuffix): src/ODVM/ImGui/ImGuiLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_ImGui_ImGuiLayer.cpp$(PreprocessSuffix) src/ODVM/ImGui/ImGuiLayer.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(ObjectSuffix): src/ODVM/Renderer/RenderCommand.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(DependSuffix) -MM src/ODVM/Renderer/RenderCommand.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/RenderCommand.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(PreprocessSuffix): src/ODVM/Renderer/RenderCommand.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_RenderCommand.cpp$(PreprocessSuffix) src/ODVM/Renderer/RenderCommand.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(ObjectSuffix): src/ODVM/Renderer/RendererAPI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(DependSuffix) -MM src/ODVM/Renderer/RendererAPI.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/RendererAPI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(PreprocessSuffix): src/ODVM/Renderer/RendererAPI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_RendererAPI.cpp$(PreprocessSuffix) src/ODVM/Renderer/RendererAPI.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(ObjectSuffix): src/ODVM/Renderer/VertexArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(DependSuffix) -MM src/ODVM/Renderer/VertexArray.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/VertexArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(PreprocessSuffix): src/ODVM/Renderer/VertexArray.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_VertexArray.cpp$(PreprocessSuffix) src/ODVM/Renderer/VertexArray.cpp

$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLContext.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLContext.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLContext.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLContext.cpp

$(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(ObjectSuffix): src/Platform/Windows/Windows.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(DependSuffix) -MM src/Platform/Windows/Windows.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/Windows/Windows.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(PreprocessSuffix): src/Platform/Windows/Windows.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_Windows_Windows.cpp$(PreprocessSuffix) src/Platform/Windows/Windows.cpp

$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLBuffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLBuffer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLBuffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLBuffer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLBuffer.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLBuffer.cpp

$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLShader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLShader.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLShader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLShader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLShader.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLShader.cpp

$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(ObjectSuffix): src/Platform/OpenGl/OpenGLTexture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(DependSuffix) -MM src/Platform/OpenGl/OpenGLTexture.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/OpenGl/OpenGLTexture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(PreprocessSuffix): src/Platform/OpenGl/OpenGLTexture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_OpenGl_OpenGLTexture.cpp$(PreprocessSuffix) src/Platform/OpenGl/OpenGLTexture.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(ObjectSuffix): src/ODVM/Renderer/Renderer2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(DependSuffix) -MM src/ODVM/Renderer/Renderer2D.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Renderer2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(PreprocessSuffix): src/ODVM/Renderer/Renderer2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Renderer2D.cpp$(PreprocessSuffix) src/ODVM/Renderer/Renderer2D.cpp

$(IntermediateDirectory)/libs_stb_stb_image.cpp$(ObjectSuffix): libs/stb/stb_image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/libs_stb_stb_image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/libs_stb_stb_image.cpp$(DependSuffix) -MM libs/stb/stb_image.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/libs/stb/stb_image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/libs_stb_stb_image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/libs_stb_stb_image.cpp$(PreprocessSuffix): libs/stb/stb_image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/libs_stb_stb_image.cpp$(PreprocessSuffix) libs/stb/stb_image.cpp

$(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(ObjectSuffix): src/ODVM/Core/LayerStack.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(DependSuffix) -MM src/ODVM/Core/LayerStack.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Core/LayerStack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(PreprocessSuffix): src/ODVM/Core/LayerStack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Core_LayerStack.cpp$(PreprocessSuffix) src/ODVM/Core/LayerStack.cpp

$(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(ObjectSuffix): src/ODVM/Renderer/Renderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(DependSuffix) -MM src/ODVM/Renderer/Renderer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Renderer/Renderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(PreprocessSuffix): src/ODVM/Renderer/Renderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Renderer_Renderer.cpp$(PreprocessSuffix) src/ODVM/Renderer/Renderer.cpp

$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(ObjectSuffix): src/ODVM/Core/Platform.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(DependSuffix) -MM src/ODVM/Core/Platform.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/ODVM/Core/Platform.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(PreprocessSuffix): src/ODVM/Core/Platform.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ODVM_Core_Platform.cpp$(PreprocessSuffix) src/ODVM/Core/Platform.cpp

$(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(ObjectSuffix): src/Platform/Windows/WindowsWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(DependSuffix) -MM src/Platform/Windows/WindowsWindow.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/ODVM/src/Platform/Windows/WindowsWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(PreprocessSuffix): src/Platform/Windows/WindowsWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Platform_Windows_WindowsWindow.cpp$(PreprocessSuffix) src/Platform/Windows/WindowsWindow.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../bin-int/Debug-linux-x86_64/ODVM/


