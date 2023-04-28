#ifndef UTILITY_SOURCE_GROUP_CXX_H
#define UTILITY_SOURCE_GROUP_CXX_H

#include <memory>
#include <string>
#include <vector>

namespace clang
{
namespace tooling
{
class JSONCompilationDatabase;
}
}	 // namespace clang

class DialogView;
class FilePath;
class SourceGroupSettingsWithCxxPchOptions;
class StorageProvider;
class Task;

namespace utility
{
std::shared_ptr<Task> createBuildPchTask(
	const SourceGroupSettingsWithCxxPchOptions* settings,
	std::vector<std::wstring> compilerFlags,
	std::shared_ptr<StorageProvider> storageProvider,
	std::shared_ptr<DialogView> dialogView);

std::shared_ptr<clang::tooling::JSONCompilationDatabase> loadCDB(
	const FilePath& cdbPath, std::string* error = nullptr);
bool containsIncludePchFlags(std::shared_ptr<clang::tooling::JSONCompilationDatabase> cdb);
bool containsIncludePchFlag(const std::vector<std::string>& args);
std::vector<std::wstring> getWithRemoveIncludePchFlag(const std::vector<std::wstring>& args);
void removeIncludePchFlag(std::vector<std::wstring>& args);
void removeWindowsFlag(std::vector<std::wstring>& args);
std::vector<std::wstring> getIncludePchFlags(const SourceGroupSettingsWithCxxPchOptions* settings);
}	 // namespace utility

#endif	  // UTILITY_SOURCE_GROUP_CXX_H
