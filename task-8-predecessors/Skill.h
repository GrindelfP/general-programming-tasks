#ifndef skill_h
#define skill_h

#include <string>

class Skill {

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
    ) {
        this->name = name;
        this->dep1 = dep1;
        this->dep2 = dep2;
        this->code = code;
    }

    std::string toString() {
        return this->name + ", " + this->dep1 + ", " + this->dep2 + ", " + this->code;
    }

    std::pair<std::string, std::string> pairNameCode() {
        return { this->name , this->code };
    }

};


#endif // skill_h