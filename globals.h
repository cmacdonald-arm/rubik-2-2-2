#ifndef GLOBALS_H
#define GLOBALS_H

#include <unordered_map>
#include <string>
#include <vector>
#include <array>

// Array of function pointers
typedef std::array<std::string (*)(std::unordered_map<std::string, std::string>&), 18> rFunctions;

const std::vector<std::vector<std::string>> gSIDES {
    {"flu", "fru", "frb", "flb"},
    {"ufl", "urf", "uel", "ure"},
    {"luf", "lfb", "lue", "leb"},
    {"rfu", "rbf", "reu", "rbe"},
    {"bfr", "blf", "ber", "ble"},
    {"elu", "eru", "erb", "elb"}
};

// e is for end
const std::vector<std::string> gCUBELETS = 
{
    // front left upper, left upper front, upper front left
    "flu", "luf", "ufl",
    // front right upper, upper right front, right front upper
    "fru", "urf", "rfu",
    // front right bottom, right bottom front, bottom front right
    "frb", "rbf", "bfr",
    // front left bottom, bottom left front, left front bottom
    "flb", "blf", "lfb",
    // End face (rear)
    // end left upper, left upper end, upper end left
    "elu", "lue", "uel",
    // end right upper, upper right end, right end upper
    "eru", "ure", "reu",
    // end right bottom, right bottom end, bottom end right
    "erb", "rbe", "ber",
    // end left bottom, bottom left end, left end bottom
    "elb", "ble", "leb"
};

// const std::unordered_map<std::string, std::vector<std::string>> gFACES ({
//     {"front", {"ful", "fur", "frb", "fbl"}}, 
//     {"upper", {"ulf", "urf", "ule", "ure"}},
//     {"left", {"lfu", "lfb", "leu", "leb"}},
//     {"right", {"rfu", "rfb", "reu", "rbe"}},
//     {"bottom", {"brf", "blf", "bre", "ble"}},
//     {"end", {"eul", "eur", "ebr", "ebl"}}
// });

// Vertex in the graph
struct Vertex
{
    std::unordered_map<std::string, std::string> m_lState;
    // if m_previousMove is "\0" then it has no parents
    std::string m_previousMove;
    // If m_previousMoveIndex is -1 then it is the start state
    int m_previousMoveIndex;

    Vertex()
        : m_lState(), m_previousMove("\0"), m_previousMoveIndex(-1) {};

    Vertex(std::unordered_map<std::string, std::string> state, std::string move, int moveIndex=-1)
        : m_lState(state), m_previousMove(move), m_previousMoveIndex(moveIndex) {};

    // Compare the m_lState unordered_maps
    bool operator==(const Vertex& rhs) const 
    {
        if (m_lState == rhs.m_lState)
        {
            return true;
        }
        return false;
    }
};

#endif 