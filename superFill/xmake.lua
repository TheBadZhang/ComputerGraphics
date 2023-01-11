add_linkdirs ("$(projectdir)")
target ("main")
	set_kind ("binary")
	add_files ("$(projectdir)/main.cpp")
	add_linkdirs ("$(projectdir)")
	set_warnings("everything")
	if is_arch ("x64") then
		add_links ("graphics64")
	elseif is_arch ("x86") then
		add_links ("graphics")
	end
	add_links ("uuid", "msimg32", "gdi32", "imm32", "ole32", "oleaut32", "winmm", "gdiplus")