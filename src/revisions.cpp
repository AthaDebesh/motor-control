#include "revisions.hpp"

Revisions::Revisions(): Revision_id("Unknown")
{
}

Revisions::~Revisions()
{
}

void Revisions::setRev(std::string Rev)
{
    Revision_id = Rev;
}

std::string Revisions::getRev()
{
    return Revision_id;
}
