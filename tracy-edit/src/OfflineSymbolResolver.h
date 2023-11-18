#ifndef __SYMBOLRESOLVER_HPP__
#define __SYMBOLRESOLVER_HPP__

#include <string>
#include <vector>
#include <regex>

namespace tracy
{
    struct CallstackFrame;
    class Worker;
}

struct FrameEntry
{
    tracy::CallstackFrame* frame = nullptr;
    uint64_t symbolOffset = 0;
};

using FrameEntryList = std::vector<FrameEntry>;

struct SymbolEntry
{
    std::string name;
    std::string file;
    int line = 0;
};

using SymbolEntryList = std::vector<SymbolEntry>;

bool ResolveSymbols( const std::string& imagePath, const FrameEntryList& inputEntryList,
                     SymbolEntryList& resolvedEntries );

using PathSubstitutionList = std::vector<std::pair<std::regex, std::string> >;

bool PatchSymbols( tracy::Worker& worker, const PathSubstitutionList& pathSubstituionlist, bool verbose = false );

#endif // __SYMBOLRESOLVER_HPP__