#ifndef REVISIONS_HPP
#define REVISIONS_HPP

#include <string>

class Revisions{
    public:
        Revisions();
        ~Revisions();

        void setRev(std::string Rev);
        std::string getRev();

    private:
    std::string Revision_id;
};

#endif