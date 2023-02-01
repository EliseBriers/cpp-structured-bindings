#ifndef USER_H
#define USER_H

#include <cstddef>
#include <string>
namespace users_correct {
struct UserScoreRecord {
    std::string userName;
    size_t score;
};

UserScoreRecord GetUserScore(size_t userId);
}

namespace users_incorrect {

std::pair<std::string, size_t> GetUserScore(size_t userId);
}

#endif // !USER_H
