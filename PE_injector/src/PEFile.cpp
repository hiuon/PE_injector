#include "../headers/PEFile.h"
#include "../headers/Checker.h"
#include "../headers/Reader.h"
#include "../headers/Writer.h"

PEFile::PEFile(const std::string& in, const std::string& out)
{
	input_path = in;
	output_path = out;
}

enum class STATUS_CODE PEFile::Read()
{
	STATUS_CODE e = read_pe_header(input_path, data_pe_header, os_type, import_addr, pe_start);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = read_sections(input_path, data_sections, pe_start, import_addr, va_gl, raw_gl);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = read_imports(input_path, data_imports, import_addr, va_gl, raw_gl);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	return STATUS_CODE::STATUS_OK;
}

enum class STATUS_CODE PEFile::Write()
{
	STATUS_CODE e = write_pe_header(output_path, data_pe_header);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = write_sections(output_path, data_sections);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = write_imports(output_path, data_imports);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	return STATUS_CODE::STATUS_OK;
}

enum class STATUS_CODE PEFile::Inject()
{

	return STATUS_CODE::STATUS_OK;
}