// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <FreezeScript/Exception.h>

using namespace std;

//
// FailureException
//
FreezeScript::FailureException::FailureException(const char* file, int line, const string& reason) :
    IceUtil::Exception(file, line), _reason(reason)
{
}

FreezeScript::FailureException::~FailureException() throw()
{
}

const char* FreezeScript::FailureException::_name = "FreezeScript::FailureException";

string
FreezeScript::FailureException::ice_id() const
{
    return _name;
}

void
FreezeScript::FailureException::ice_print(ostream& out) const
{
    ::IceUtil::Exception::ice_print(out);
    out << ":\nerror occurred during transformation"; // TODO
    if(!_reason.empty())
    {
        out << ":\n" << _reason;
    }
}

FreezeScript::FailureException*
FreezeScript::FailureException::ice_clone() const
{
    return new FailureException(ice_file(), ice_line(), _reason);
}

void
FreezeScript::FailureException::ice_throw() const
{
    throw *this;
}

string
FreezeScript::FailureException::reason() const
{
    return _reason;
}
