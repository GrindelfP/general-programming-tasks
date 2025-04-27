#ifndef skill_h
#define skill_h

#include <string>
#include <ostream>

class Skill {

private:
    std::string trim(const std::string& str) {
        auto first = str.begin();
        while (first != str.end() && std::isspace(*first)) {
            ++first;
        }

        auto last = str.end();
        while (last != first && std::isspace(*std::prev(last))) {
            --last;
        }

        return std::string(first, last);
    }

public:
    std::string name;
    std::string dep1;
    std::string dep2;
    std::string code;

    Skill(
        std::string name,
        std::string dep1,
        std::string dep2,
        std::string code
    ) : name(trim(name)), dep1(trim(dep1)), dep2(trim(dep2)), code(trim(code)) {}

    std::string toString() const {
        return this->name + ", " + this->dep1 + ", " + this->dep2 + ", " + this->code;
    }

    std::pair<std::string, std::string> pairNameCode() const {
        return { this->name , this->code };
    }

    friend std::ostream& operator<<(std::ostream &os, const Skill &skill) {
        os << skill.toString();
        return os;
    }
};

#endif // skill_h
