// ======================================================================
// \title  TestLog/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for TestLog component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================

#ifndef TestLog_GTEST_BASE_HPP
#define TestLog_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for event history assertions 
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SomeEvent_SIZE(size) \
  this->assertEvents_SomeEvent_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SomeEvent(index, _arg1, _arg2, _arg3) \
  this->assertEvents_SomeEvent(__FILE__, __LINE__, index, _arg1, _arg2, _arg3)

namespace Somewhere {

  //! \class TestLogGTestBase
  //! \brief Auto-generated base class for TestLog component Google Test harness
  //!
  class TestLogGTestBase :
    public TestLogTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object TestLogGTestBase
      //!
      TestLogGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object TestLogGTestBase
      //!
      virtual ~TestLogGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SomeEvent
      // ----------------------------------------------------------------------

      void assertEvents_SomeEvent_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SomeEvent(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const I32 arg1, /*!< The I32 command argument*/
          const char *const arg2, /*!< The F32 command argument*/
          const U8 arg3 /*!< The U8 command argument*/
      ) const;

  };

} // end namespace Somewhere

#endif
