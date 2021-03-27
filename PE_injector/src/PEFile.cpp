#include "../headers/PEFile.h"
#include "../headers/Checker.h"
#include "../headers/Reader.h"
#include "../headers/Writer.h"

PEFile::PEFile(const std::string& in, const std::string& out)
{
	input_path = in;
	output_path = out;
}

int PEFile::Read()
{
	read_pe_header(input_path, data_pe_header, os_type, import_addr, pe_start);
	read_sections(input_path, data_sections, pe_start, import_addr, va_gl, raw_gl);
	read_imports(input_path, data_imports, import_addr, va_gl, raw_gl);
	return STATUS_OK;
}

int PEFile::Write()
{
	write_pe_header(output_path, data_pe_header);
	write_sections(output_path, data_sections);
	write_imports(output_path, data_imports);
	return 0;
}

int PEFile::Inject()
{
	return 0;
}