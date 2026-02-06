// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME V1720Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "V1720FileSetup.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void delete_V1720FileSetup(void *p);
   static void deleteArray_V1720FileSetup(void *p);
   static void destruct_V1720FileSetup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::V1720FileSetup*)
   {
      ::V1720FileSetup *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::V1720FileSetup >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("V1720FileSetup", ::V1720FileSetup::Class_Version(), "V1720FileSetup.h", 22,
                  typeid(::V1720FileSetup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::V1720FileSetup::Dictionary, isa_proxy, 4,
                  sizeof(::V1720FileSetup) );
      instance.SetDelete(&delete_V1720FileSetup);
      instance.SetDeleteArray(&deleteArray_V1720FileSetup);
      instance.SetDestructor(&destruct_V1720FileSetup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::V1720FileSetup*)
   {
      return GenerateInitInstanceLocal(static_cast<::V1720FileSetup*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::V1720FileSetup*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr V1720FileSetup::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *V1720FileSetup::Class_Name()
{
   return "V1720FileSetup";
}

//______________________________________________________________________________
const char *V1720FileSetup::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::V1720FileSetup*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int V1720FileSetup::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::V1720FileSetup*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *V1720FileSetup::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::V1720FileSetup*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *V1720FileSetup::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::V1720FileSetup*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void V1720FileSetup::Streamer(TBuffer &R__b)
{
   // Stream an object of class V1720FileSetup.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(V1720FileSetup::Class(),this);
   } else {
      R__b.WriteClassBuffer(V1720FileSetup::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_V1720FileSetup(void *p) {
      delete (static_cast<::V1720FileSetup*>(p));
   }
   static void deleteArray_V1720FileSetup(void *p) {
      delete [] (static_cast<::V1720FileSetup*>(p));
   }
   static void destruct_V1720FileSetup(void *p) {
      typedef ::V1720FileSetup current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::V1720FileSetup

namespace ROOT {
   static TClass *unordered_maplEstringcOBranchDatagR_Dictionary();
   static void unordered_maplEstringcOBranchDatagR_TClassManip(TClass*);
   static void *new_unordered_maplEstringcOBranchDatagR(void *p = nullptr);
   static void *newArray_unordered_maplEstringcOBranchDatagR(Long_t size, void *p);
   static void delete_unordered_maplEstringcOBranchDatagR(void *p);
   static void deleteArray_unordered_maplEstringcOBranchDatagR(void *p);
   static void destruct_unordered_maplEstringcOBranchDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<string,BranchData>*)
   {
      unordered_map<string,BranchData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<string,BranchData>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<string,BranchData>", -2, "unordered_map", 109,
                  typeid(unordered_map<string,BranchData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEstringcOBranchDatagR_Dictionary, isa_proxy, 0,
                  sizeof(unordered_map<string,BranchData>) );
      instance.SetNew(&new_unordered_maplEstringcOBranchDatagR);
      instance.SetNewArray(&newArray_unordered_maplEstringcOBranchDatagR);
      instance.SetDelete(&delete_unordered_maplEstringcOBranchDatagR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEstringcOBranchDatagR);
      instance.SetDestructor(&destruct_unordered_maplEstringcOBranchDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<string,BranchData> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<string,BranchData>","std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, BranchData, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, BranchData> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<string,BranchData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEstringcOBranchDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<string,BranchData>*>(nullptr))->GetClass();
      unordered_maplEstringcOBranchDatagR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEstringcOBranchDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEstringcOBranchDatagR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<string,BranchData> : new unordered_map<string,BranchData>;
   }
   static void *newArray_unordered_maplEstringcOBranchDatagR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<string,BranchData>[nElements] : new unordered_map<string,BranchData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEstringcOBranchDatagR(void *p) {
      delete (static_cast<unordered_map<string,BranchData>*>(p));
   }
   static void deleteArray_unordered_maplEstringcOBranchDatagR(void *p) {
      delete [] (static_cast<unordered_map<string,BranchData>*>(p));
   }
   static void destruct_unordered_maplEstringcOBranchDatagR(void *p) {
      typedef unordered_map<string,BranchData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<string,BranchData>

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_libV1720() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_libV1720) = RecordReadRules_libV1720();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_libV1720));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_libV1720_Impl() {
    static const char* headers[] = {
"V1720FileSetup.h",
nullptr
    };
    static const char* includePaths[] = {
"/home/lasitha/MyFiles/Root/proj2-SDK",
"/home/lasitha/MyFiles/Root/proj2-SDK",
"/opt/root/include",
"/opt/root/include/",
"/home/lasitha/MyFiles/Root/proj2-SDK/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libV1720 dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$V1720FileSetup.h")))  V1720FileSetup;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libV1720 dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "V1720FileSetup.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"V1720FileSetup", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libV1720",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libV1720_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libV1720_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libV1720() {
  TriggerDictionaryInitialization_libV1720_Impl();
}
