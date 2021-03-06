/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018, 2019 TrueBlocks, LLC (http://trueblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <algorithm>
#include "monitorcacheitem.h"

namespace qblocks {

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CMonitorCacheItem, CAccountName);

//---------------------------------------------------------------------------
static string_q nextMonitorcacheitemChunk(const string_q& fieldIn, const void* dataPtr);
static string_q nextMonitorcacheitemChunk_custom(const string_q& fieldIn, const void* dataPtr);

//---------------------------------------------------------------------------
void CMonitorCacheItem::Format(ostream& ctx, const string_q& fmtIn, void* dataPtr) const {
    if (!m_showing)
        return;

    // EXISTING_CODE
    // EXISTING_CODE

    string_q fmt = (fmtIn.empty() ? expContext().fmtMap["monitorcacheitem_fmt"] : fmtIn);
    if (fmt.empty()) {
        toJson(ctx);
        return;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextMonitorcacheitemChunk, this);
}

//---------------------------------------------------------------------------
string_q nextMonitorcacheitemChunk(const string_q& fieldIn, const void* dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CMonitorCacheItem*>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------
string_q CMonitorCacheItem::getValueByName(const string_q& fieldName) const {
    // Give customized code a chance to override first
    string_q ret = nextMonitorcacheitemChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // EXISTING_CODE
    // EXISTING_CODE

    // Return field values
    switch (tolower(fieldName[0])) {
        case 'd':
            if (fieldName % "deleted") {
                return bool_2_Str(deleted);
            }
            break;
        case 's':
            if (fieldName % "sizeInBytes2") {
                return uint_2_Str(sizeInBytes2);
            }
            break;
        case 't':
            if (fieldName % "type") {
                return type;
            }
            break;
        default:
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CAccountName::getValueByName(fieldName);
}

//---------------------------------------------------------------------------------------------------
bool CMonitorCacheItem::setValueByName(const string_q& fieldNameIn, const string_q& fieldValueIn) {
    string_q fieldName = fieldNameIn;
    string_q fieldValue = fieldValueIn;

    // EXISTING_CODE
    // EXISTING_CODE

    if (CAccountName::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case 'd':
            if (fieldName % "deleted") {
                deleted = str_2_Bool(fieldValue);
                return true;
            }
            break;
        case 's':
            if (fieldName % "sizeInBytes2") {
                sizeInBytes2 = str_2_Uint(fieldValue);
                return true;
            }
            break;
        case 't':
            if (fieldName % "type") {
                type = fieldValue;
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CMonitorCacheItem::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CMonitorCacheItem::Serialize(CArchive& archive) {
    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CAccountName::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> type;
    archive >> deleted;
    archive >> sizeInBytes2;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CMonitorCacheItem::SerializeC(CArchive& archive) const {
    // Writing always write the latest version of the data
    CAccountName::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << type;
    archive << deleted;
    archive << sizeInBytes2;

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CMonitorCacheItemArray& array) {
    uint64_t count;
    archive >> count;
    array.resize(count);
    for (size_t i = 0; i < count; i++) {
        ASSERT(i < array.capacity());
        array.at(i).Serialize(archive);
    }
    return archive;
}

//---------------------------------------------------------------------------
CArchive& operator<<(CArchive& archive, const CMonitorCacheItemArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0; i < array.size(); i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CMonitorCacheItem::registerClass(void) {
    // only do this once
    if (HAS_FIELD(CMonitorCacheItem, "schema"))
        return;

    CAccountName::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(CMonitorCacheItem, "schema", T_NUMBER, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "deleted", T_BOOL, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "showing", T_BOOL, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "cname", T_TEXT, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "type", T_TEXT | TS_OMITEMPTY, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "deleted", T_BOOL | TS_OMITEMPTY, ++fieldNum);
    ADD_FIELD(CMonitorCacheItem, "sizeInBytes2", T_UNUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CMonitorCacheItem, "schema");
    HIDE_FIELD(CMonitorCacheItem, "deleted");
    HIDE_FIELD(CMonitorCacheItem, "showing");
    HIDE_FIELD(CMonitorCacheItem, "cname");

    builtIns.push_back(_biCMonitorCacheItem);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextMonitorcacheitemChunk_custom(const string_q& fieldIn, const void* dataPtr) {
    const CMonitorCacheItem* mon = reinterpret_cast<const CMonitorCacheItem*>(dataPtr);
    if (mon) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if (fieldIn % "parsed")
                    return nextBasenodeChunk(fieldIn, mon);
                // EXISTING_CODE
                // EXISTING_CODE
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool CMonitorCacheItem::readBackLevel(CArchive& archive) {
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CMonitorCacheItem& it) {
    // EXISTING_CODE
    // EXISTING_CODE

    it.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
const char* STR_DISPLAY_MONITORCACHEITEM =
    "[{DISPLAY_NAME}]\t"
    "[{FIRSTAPPEARANCE}]\t"
    "[{LASTAPPEARANCE}]\t"
    "[{APPEARANCERANGE}]\t"
    "[{NRECORDS}]\t"
    "[{APPEARANCEINTERVAL}]\t"
    "[{SIZEINBYTES}]\t"
    "[{SIZEINBYTES2}]\t"
    "[{CURETHER}]";

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE
}  // namespace qblocks
