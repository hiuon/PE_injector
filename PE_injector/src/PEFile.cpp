#include "../headers/PEFile.h"
#include "../headers/Checker.h"
#include "../headers/Reader.h"
#include "../headers/Writer.h"
#include "../headers/Injector.h"
#include "../headers/status_code.h"

PEFile::PEFile(const std::string& in, const std::string& out)
{
	input_path = in;
	output_path = out;
}

STATUS_CODE PEFile::Read()
{
	STATUS_CODE e = read_pe_header(input_path, data_pe_header, os_type, import_addr, pe_start);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = read_sections(input_path, data_sections, pe_start, import_addr, va_gl, raw_gl, virt_size, size_raw_data, pointer_to_section);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	e = read_imports(input_path, data_imports, import_addr, va_gl, raw_gl, number_of_imports);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}
	return STATUS_CODE::STATUS_OK;
}

STATUS_CODE PEFile::Write()
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

STATUS_CODE PEFile::Inject(bool is_stealth)
{
	STATUS_CODE e = STATUS_CODE::STATUS_OK;
	if (is_stealth) e = check_dot_net_and_signature(input_path, pe_start);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}

	e = check_file_for_inject(virt_size, size_raw_data, number_of_imports);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}

	

	e = inject(input_path, output_path, import_addr, number_of_imports, size_raw_data, raw_gl, va_gl, pointer_to_section, pe_start);
	if (e != STATUS_CODE::STATUS_OK) {
		return e;
	}


	return STATUS_CODE::STATUS_OK;
}