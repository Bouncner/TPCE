/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors
 * - Doug Johnson
 */

//
// Include this module's header first to make sure it is self-contained
//
#include "../inc/SecurityDataFileRecordTestCases.h"

//
// Include system headers
//
#include <stdlib.h>

//
// Include application headers
//
#include "../../../Utilities/inc/EGenStandardTypes.h"
#include "../../../Test/inc/TestUtilities.h"
#include "../inc/Utilities.h"

using namespace EGenTestCommon;

namespace EGenInputFilesTest
{
    //
    // Constructor / Destructor
    //
    SecurityDataFileRecordTestCases::SecurityDataFileRecordTestCases()
        : dfr1( 0 )
        , s_id("1")
        , s_st_id("ACTV")
        , s_symb("ZICA")
        , s_issue("COMMON")
        , s_ex_id("PCX")
        , s_co_id("1")
    {
        fields.push_back(s_id);
        fields.push_back(s_st_id);
        fields.push_back(s_symb);
        fields.push_back(s_issue);
        fields.push_back(s_ex_id);
        fields.push_back(s_co_id);
    }

    SecurityDataFileRecordTestCases::~SecurityDataFileRecordTestCases()
    {
        CleanUp( &dfr1 );
    }

    //
    // Add test cases to the test suite.
    //
    void SecurityDataFileRecordTestCases::AddTestCases( boost::unit_test::test_suite* testSuite, boost::shared_ptr< SecurityDataFileRecordTestCases > tester ) const
    {
        AddTestCase( "SecurityDataFileRecord: TestCase_DFRConstructor", &TestCase_DFRConstructor<TPCE::SecurityDataFileRecord>, fields, testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, TIdent>( "SecurityDataFileRecord: TestCase_S_ID", &TestCase_DFRField<TPCE::SecurityDataFileRecord, TIdent>, fields, &TPCE::SecurityDataFileRecord::S_ID, atoi(s_id.c_str()), testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, const std::string&>( "SecurityDataFileRecord: TestCase_S_ST_ID", &TestCase_DFRField<TPCE::SecurityDataFileRecord, const std::string&>, fields, &TPCE::SecurityDataFileRecord::S_ST_ID, s_st_id, testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, const std::string&>( "SecurityDataFileRecord: TestCase_S_SYMB", &TestCase_DFRField<TPCE::SecurityDataFileRecord, const std::string&>, fields, &TPCE::SecurityDataFileRecord::S_SYMB, s_symb, testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, const std::string&>( "SecurityDataFileRecord: TestCase_S_ISSUE", &TestCase_DFRField<TPCE::SecurityDataFileRecord, const std::string&>, fields, &TPCE::SecurityDataFileRecord::S_ISSUE, s_issue, testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, const std::string&>( "SecurityDataFileRecord: TestCase_S_EX_ID", &TestCase_DFRField<TPCE::SecurityDataFileRecord, const std::string&>, fields, &TPCE::SecurityDataFileRecord::S_EX_ID, s_ex_id, testSuite );
        AddTestCaseField<TPCE::SecurityDataFileRecord, TIdent>( "SecurityDataFileRecord: TestCase_S_CO_ID", &TestCase_DFRField<TPCE::SecurityDataFileRecord, TIdent>, fields, &TPCE::SecurityDataFileRecord::S_CO_ID, atoi(s_co_id.c_str()), testSuite );
        AddTestCase( "SecurityDataFileRecord: TestCase_DFRToString", &TestCase_DFRMultiFieldToString<TPCE::SecurityDataFileRecord>, fields, testSuite );
    }

} // namespace EGenUtilitiesTest
