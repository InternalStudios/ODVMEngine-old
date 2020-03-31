##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Sandbox
ConfigurationName      :=Debug
WorkspacePath          :=/home/sfulham/dev/ODVMEngine
ProjectPath            :=/home/sfulham/dev/ODVMEngine/Sandbox
IntermediateDirectory  :=../bin-int/Debug-linux-x86_64/Sandbox
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Shaun Fulham
Date                   :=28/03/20
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
OutputFile             :=../bin/Debug-linux-x86_64/Sandbox/Sandbox
Preprocessors          :=$(PreprocessorSwitch)_GLFW_X11 $(PreprocessorSwitch)ODVM_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Sandbox.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -m64 ../bin/Debug-linux-x86_64/ODVM/libODVM.a ../ODVM/libs/GLFW/bin/Debug-linux-x86_64/GLFW/libGLFW.a ../ODVM/libs/Discord/bin/Debug-linux-x86_64/Discord/libDiscord.a ../ODVM/libs/Glad/bin/Debug-linux-x86_64/Glad/libGlad.a ../ODVM/libs/ImGui/bin/Debug-linux-x86_64/ImGui/libImGui.a -ldl -lm -lX11 -lXinerama -lXi -lXcursor -lpthread -lXrandr -lrt
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../ODVM/libs/spdlog/include $(IncludeSwitch)../ODVM/src $(IncludeSwitch)../ODVM/libs/glm $(IncludeSwitch)../ODVM/libs/ImGui $(IncludeSwitch)../ODVM/libs/GLFW/include $(IncludeSwitch)../ODVM/libs/discord/cpp $(IncludeSwitch)../ODVM/libs/Vulkan/latest/Include 
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
Objects0=$(IntermediateDirectory)/src_VulkanLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Application.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Sandbox2D.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "../.build-debug/ODVM" "../.build-debug/GLFW" "../.build-debug/Discord" "../.build-debug/Glad" "../.build-debug/ImGui" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"../.build-debug/ODVM":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/ODVM"


"../.build-debug/GLFW":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/GLFW"


"../.build-debug/Discord":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/Discord"


"../.build-debug/Glad":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/Glad"


"../.build-debug/ImGui":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/ImGui"




MakeIntermediateDirs:
	@test -d ../bin-int/Debug-linux-x86_64/Sandbox || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/Sandbox


$(IntermediateDirectory)/.d:
	@test -d ../bin-int/Debug-linux-x86_64/Sandbox || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/Sandbox

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_VulkanLayer.cpp$(ObjectSuffix): src/VulkanLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VulkanLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VulkanLayer.cpp$(DependSuffix) -MM src/VulkanLayer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/Sandbox/src/VulkanLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VulkanLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VulkanLayer.cpp$(PreprocessSuffix): src/VulkanLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VulkanLayer.cpp$(PreprocessSuffix) src/VulkanLayer.cpp

$(IntermediateDirectory)/src_Application.cpp$(ObjectSuffix): src/Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Application.cpp$(DependSuffix) -MM src/Application.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/Sandbox/src/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Application.cpp$(PreprocessSuffix): src/Application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Application.cpp$(PreprocessSuffix) src/Application.cpp

$(IntermediateDirectory)/src_Sandbox2D.cpp$(ObjectSuffix): src/Sandbox2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Sandbox2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Sandbox2D.cpp$(DependSuffix) -MM src/Sandbox2D.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/dev/ODVMEngine/Sandbox/src/Sandbox2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Sandbox2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Sandbox2D.cpp$(PreprocessSuffix): src/Sandbox2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Sandbox2D.cpp$(PreprocessSuffix) src/Sandbox2D.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../bin-int/Debug-linux-x86_64/Sandbox/


