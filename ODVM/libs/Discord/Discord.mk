##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Discord
ConfigurationName      :=Debug
WorkspacePath          :=/home/sfulham/odvmengine/ODVMEngine
ProjectPath            :=/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord
IntermediateDirectory  :=bin-int/Debug-linux-x86_64/Discord
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/19/20
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
OutputFile             :=bin/Debug-linux-x86_64/Discord/libDiscord.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Discord.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -m64
IncludePath            :=  $(IncludeSwitch). 
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
Objects0=$(IntermediateDirectory)/cpp_voice_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_user_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_core.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_application_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_image_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_lobby_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_activity_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_store_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_achievement_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_types.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/cpp_network_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_relationship_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_overlay_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_storage_manager.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/sfulham/odvmengine/ODVMEngine/.build-debug"
	@echo rebuilt > "/home/sfulham/odvmengine/ODVMEngine/.build-debug/Discord"

MakeIntermediateDirs:
	@test -d bin-int/Debug-linux-x86_64/Discord || $(MakeDirCommand) bin-int/Debug-linux-x86_64/Discord


bin-int/Debug-linux-x86_64/Discord:
	@test -d bin-int/Debug-linux-x86_64/Discord || $(MakeDirCommand) bin-int/Debug-linux-x86_64/Discord

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/cpp_voice_manager.cpp$(ObjectSuffix): cpp/voice_manager.cpp $(IntermediateDirectory)/cpp_voice_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/voice_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_voice_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_voice_manager.cpp$(DependSuffix): cpp/voice_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_voice_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_voice_manager.cpp$(DependSuffix) -MM cpp/voice_manager.cpp

$(IntermediateDirectory)/cpp_voice_manager.cpp$(PreprocessSuffix): cpp/voice_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_voice_manager.cpp$(PreprocessSuffix) cpp/voice_manager.cpp

$(IntermediateDirectory)/cpp_user_manager.cpp$(ObjectSuffix): cpp/user_manager.cpp $(IntermediateDirectory)/cpp_user_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/user_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_user_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_user_manager.cpp$(DependSuffix): cpp/user_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_user_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_user_manager.cpp$(DependSuffix) -MM cpp/user_manager.cpp

$(IntermediateDirectory)/cpp_user_manager.cpp$(PreprocessSuffix): cpp/user_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_user_manager.cpp$(PreprocessSuffix) cpp/user_manager.cpp

$(IntermediateDirectory)/cpp_core.cpp$(ObjectSuffix): cpp/core.cpp $(IntermediateDirectory)/cpp_core.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/core.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_core.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_core.cpp$(DependSuffix): cpp/core.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_core.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_core.cpp$(DependSuffix) -MM cpp/core.cpp

$(IntermediateDirectory)/cpp_core.cpp$(PreprocessSuffix): cpp/core.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_core.cpp$(PreprocessSuffix) cpp/core.cpp

$(IntermediateDirectory)/cpp_application_manager.cpp$(ObjectSuffix): cpp/application_manager.cpp $(IntermediateDirectory)/cpp_application_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/application_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_application_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_application_manager.cpp$(DependSuffix): cpp/application_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_application_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_application_manager.cpp$(DependSuffix) -MM cpp/application_manager.cpp

$(IntermediateDirectory)/cpp_application_manager.cpp$(PreprocessSuffix): cpp/application_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_application_manager.cpp$(PreprocessSuffix) cpp/application_manager.cpp

$(IntermediateDirectory)/cpp_image_manager.cpp$(ObjectSuffix): cpp/image_manager.cpp $(IntermediateDirectory)/cpp_image_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/image_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_image_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_image_manager.cpp$(DependSuffix): cpp/image_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_image_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_image_manager.cpp$(DependSuffix) -MM cpp/image_manager.cpp

$(IntermediateDirectory)/cpp_image_manager.cpp$(PreprocessSuffix): cpp/image_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_image_manager.cpp$(PreprocessSuffix) cpp/image_manager.cpp

$(IntermediateDirectory)/cpp_lobby_manager.cpp$(ObjectSuffix): cpp/lobby_manager.cpp $(IntermediateDirectory)/cpp_lobby_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/lobby_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_lobby_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_lobby_manager.cpp$(DependSuffix): cpp/lobby_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_lobby_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_lobby_manager.cpp$(DependSuffix) -MM cpp/lobby_manager.cpp

$(IntermediateDirectory)/cpp_lobby_manager.cpp$(PreprocessSuffix): cpp/lobby_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_lobby_manager.cpp$(PreprocessSuffix) cpp/lobby_manager.cpp

$(IntermediateDirectory)/cpp_activity_manager.cpp$(ObjectSuffix): cpp/activity_manager.cpp $(IntermediateDirectory)/cpp_activity_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/activity_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_activity_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_activity_manager.cpp$(DependSuffix): cpp/activity_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_activity_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_activity_manager.cpp$(DependSuffix) -MM cpp/activity_manager.cpp

$(IntermediateDirectory)/cpp_activity_manager.cpp$(PreprocessSuffix): cpp/activity_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_activity_manager.cpp$(PreprocessSuffix) cpp/activity_manager.cpp

$(IntermediateDirectory)/cpp_store_manager.cpp$(ObjectSuffix): cpp/store_manager.cpp $(IntermediateDirectory)/cpp_store_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/store_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_store_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_store_manager.cpp$(DependSuffix): cpp/store_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_store_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_store_manager.cpp$(DependSuffix) -MM cpp/store_manager.cpp

$(IntermediateDirectory)/cpp_store_manager.cpp$(PreprocessSuffix): cpp/store_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_store_manager.cpp$(PreprocessSuffix) cpp/store_manager.cpp

$(IntermediateDirectory)/cpp_achievement_manager.cpp$(ObjectSuffix): cpp/achievement_manager.cpp $(IntermediateDirectory)/cpp_achievement_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/achievement_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_achievement_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_achievement_manager.cpp$(DependSuffix): cpp/achievement_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_achievement_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_achievement_manager.cpp$(DependSuffix) -MM cpp/achievement_manager.cpp

$(IntermediateDirectory)/cpp_achievement_manager.cpp$(PreprocessSuffix): cpp/achievement_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_achievement_manager.cpp$(PreprocessSuffix) cpp/achievement_manager.cpp

$(IntermediateDirectory)/cpp_types.cpp$(ObjectSuffix): cpp/types.cpp $(IntermediateDirectory)/cpp_types.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/types.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_types.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_types.cpp$(DependSuffix): cpp/types.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_types.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_types.cpp$(DependSuffix) -MM cpp/types.cpp

$(IntermediateDirectory)/cpp_types.cpp$(PreprocessSuffix): cpp/types.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_types.cpp$(PreprocessSuffix) cpp/types.cpp

$(IntermediateDirectory)/cpp_network_manager.cpp$(ObjectSuffix): cpp/network_manager.cpp $(IntermediateDirectory)/cpp_network_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/network_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_network_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_network_manager.cpp$(DependSuffix): cpp/network_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_network_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_network_manager.cpp$(DependSuffix) -MM cpp/network_manager.cpp

$(IntermediateDirectory)/cpp_network_manager.cpp$(PreprocessSuffix): cpp/network_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_network_manager.cpp$(PreprocessSuffix) cpp/network_manager.cpp

$(IntermediateDirectory)/cpp_relationship_manager.cpp$(ObjectSuffix): cpp/relationship_manager.cpp $(IntermediateDirectory)/cpp_relationship_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/relationship_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_relationship_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_relationship_manager.cpp$(DependSuffix): cpp/relationship_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_relationship_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_relationship_manager.cpp$(DependSuffix) -MM cpp/relationship_manager.cpp

$(IntermediateDirectory)/cpp_relationship_manager.cpp$(PreprocessSuffix): cpp/relationship_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_relationship_manager.cpp$(PreprocessSuffix) cpp/relationship_manager.cpp

$(IntermediateDirectory)/cpp_overlay_manager.cpp$(ObjectSuffix): cpp/overlay_manager.cpp $(IntermediateDirectory)/cpp_overlay_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/overlay_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_overlay_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_overlay_manager.cpp$(DependSuffix): cpp/overlay_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_overlay_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_overlay_manager.cpp$(DependSuffix) -MM cpp/overlay_manager.cpp

$(IntermediateDirectory)/cpp_overlay_manager.cpp$(PreprocessSuffix): cpp/overlay_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_overlay_manager.cpp$(PreprocessSuffix) cpp/overlay_manager.cpp

$(IntermediateDirectory)/cpp_storage_manager.cpp$(ObjectSuffix): cpp/storage_manager.cpp $(IntermediateDirectory)/cpp_storage_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Discord/cpp/storage_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_storage_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_storage_manager.cpp$(DependSuffix): cpp/storage_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_storage_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_storage_manager.cpp$(DependSuffix) -MM cpp/storage_manager.cpp

$(IntermediateDirectory)/cpp_storage_manager.cpp$(PreprocessSuffix): cpp/storage_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_storage_manager.cpp$(PreprocessSuffix) cpp/storage_manager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r bin-int/Debug-linux-x86_64/Discord/


