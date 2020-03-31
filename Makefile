.PHONY: clean All

All:
	@echo "----------Building project:[ ODVM - Debug ]----------"
	@cd "ODVM" && "$(MAKE)" -f  "ODVM.mk"
	@echo "----------Building project:[ GLFW - Debug ]----------"
	@cd "ODVM/libs/GLFW" && "$(MAKE)" -f  "GLFW.mk"
	@echo "----------Building project:[ Discord - Debug ]----------"
	@cd "ODVM/libs/Discord" && "$(MAKE)" -f  "Discord.mk"
	@echo "----------Building project:[ Glad - Debug ]----------"
	@cd "ODVM/libs/Glad" && "$(MAKE)" -f  "Glad.mk"
	@echo "----------Building project:[ ImGui - Debug ]----------"
	@cd "ODVM/libs/ImGui" && "$(MAKE)" -f  "ImGui.mk"
	@echo "----------Building project:[ Sandbox - Debug ]----------"
	@cd "Sandbox" && "$(MAKE)" -f  "Sandbox.mk"
clean:
	@echo "----------Cleaning project:[ ODVM - Debug ]----------"
	@cd "ODVM" && "$(MAKE)" -f  "ODVM.mk"  clean
	@echo "----------Cleaning project:[ GLFW - Debug ]----------"
	@cd "ODVM/libs/GLFW" && "$(MAKE)" -f  "GLFW.mk"  clean
	@echo "----------Cleaning project:[ Discord - Debug ]----------"
	@cd "ODVM/libs/Discord" && "$(MAKE)" -f  "Discord.mk"  clean
	@echo "----------Cleaning project:[ Glad - Debug ]----------"
	@cd "ODVM/libs/Glad" && "$(MAKE)" -f  "Glad.mk"  clean
	@echo "----------Cleaning project:[ ImGui - Debug ]----------"
	@cd "ODVM/libs/ImGui" && "$(MAKE)" -f  "ImGui.mk"  clean
	@echo "----------Cleaning project:[ Sandbox - Debug ]----------"
	@cd "Sandbox" && "$(MAKE)" -f  "Sandbox.mk" clean
