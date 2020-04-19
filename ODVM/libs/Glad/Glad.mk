##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Glad
ConfigurationName      :=Debug
WorkspacePath          :=/home/sfulham/odvmengine/ODVMEngine
ProjectPath            :=/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Glad
IntermediateDirectory  :=bin-int/Debug-linux-x86_64/Glad
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/19/20
CodeLitePath           :=/home/sfulham/.codelite
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
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
OutputFile             :=bin/Debug-linux-x86_64/Glad/libGlad.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Glad.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -m64
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)include 
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
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -m64 -g $(Preprocessors)
CFLAGS   :=  -m64 -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_glad.c$(ObjectSuffix) 



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
	@echo rebuilt > "/home/sfulham/odvmengine/ODVMEngine/.build-debug/Glad"

MakeIntermediateDirs:
	@test -d bin-int/Debug-linux-x86_64/Glad || $(MakeDirCommand) bin-int/Debug-linux-x86_64/Glad


bin-int/Debug-linux-x86_64/Glad:
	@test -d bin-int/Debug-linux-x86_64/Glad || $(MakeDirCommand) bin-int/Debug-linux-x86_64/Glad

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_glad.c$(ObjectSuffix): src/glad.c $(IntermediateDirectory)/src_glad.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sfulham/odvmengine/ODVMEngine/ODVM/libs/Glad/src/glad.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_glad.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_glad.c$(DependSuffix): src/glad.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_glad.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_glad.c$(DependSuffix) -MM src/glad.c

$(IntermediateDirectory)/src_glad.c$(PreprocessSuffix): src/glad.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_glad.c$(PreprocessSuffix) src/glad.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r bin-int/Debug-linux-x86_64/Glad/


