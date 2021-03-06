#include "json/json_null.hpp"

namespace oos {

const char *json_null::null_string = "null";

json_null::json_null(void)
  : json_type("json_null")
{}

json_null::~json_null(void)
{}

bool json_null::parse(std::istream &in)
{
  // skip white
  in >> std::ws;
  
  // parse string
  char c = in.get();

  if (!in.good()) {
    return false;
  }

  int i = 1;
  if (c == 'n') {
    // check for "null"
    while (in && i < 4) {
      c = in.get();
      if (!in.good()) {
        return false;
      }
      if (json_null::null_string[i++] != c) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

void json_null::print(std::ostream &out) const
{
  out << json_null::null_string;
}

}
