#include "pch.h"
#include "DeleteKeyCommand.h"
#include "Registry.h"
#include "Helpers.h"

DeleteKeyCommand::DeleteKeyCommand(PCWSTR path, PCWSTR name, AppCommandCallback<DeleteKeyCommand> cb)
	: RegAppCommandBase(L"Delete Key " + CString(name), path, name, cb) {
}

bool DeleteKeyCommand::Execute() {
	auto key = Registry::OpenKey(_path, MAXIMUM_ALLOWED);
	if (!key)
		return false;

	auto error = ERROR_SUCCESS;
	::SetLastError(error = ::RegDeleteTree(key.Get(), _name));
	if (ERROR_SUCCESS != error)
		return false;

	return InvokeCallback(true);
}

bool DeleteKeyCommand::Undo() {
	::SetLastError(ERROR_NOT_SUPPORTED);
	return false;
}
