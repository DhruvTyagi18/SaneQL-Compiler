#ifndef H_saneql_SQLWriter
#define H_saneql_SQLWriter
//---------------------------------------------------------------------------
#include <string>
#include <experimental/string_view>
#include <unordered_map>
//---------------------------------------------------------------------------
// SaneQL
// (c) 2023 Thomas Neumann
// SPDX-License-Identifier: BSD-3-Clause
//---------------------------------------------------------------------------
namespace saneql {
//---------------------------------------------------------------------------
class Type;
//---------------------------------------------------------------------------
namespace algebra {
class IU;
}
//---------------------------------------------------------------------------
/// Helper class to generate SQL
class SQLWriter {
   private:
   /// The result buffer
   std::string result;
   /// The current target
   std::string* target;
   /// All assigned IU names
   std::unordered_map<const algebra::IU*, std::string> iuNames;

   public:
   /// Constructor
   SQLWriter();
   /// Destructor
   ~SQLWriter();

   /// Write a SQL fragment
   void write(std::experimental::string_view sql);
   /// Write an identifier, quoting as needed
   void writeIdentifier(std::experimental::string_view identifier);
   /// Write an IU
   void writeIU(const algebra::IU* iu);
   /// Write a string literal
   void writeString(std::experimental::string_view str);
   /// Write a type
   void writeType(Type type);

   /// Get the result
   std::string getResult() const { return result; }
};
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif
