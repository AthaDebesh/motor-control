#ifndef REVISIONS_HPP
#define REVISIONS_HPP

#include <string>

class Revisions{
    public:
        Revisions(const std::string& uniqueID);
        ~Revisions();

        virtual void setRev(std::string Rev) = 0;
        virtual std::string getRev() = 0;

    protected:
    std::string Revision_id;
    std::string id;
};

#endif