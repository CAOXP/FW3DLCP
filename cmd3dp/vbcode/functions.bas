Attribute VB_Name = "Functions"
Option Explicit

'¶Á³ö×Ô¶¨ÒåINIÎÄ¼þ
Private Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
'Ð´Èë×Ô¶¨ÒåINIÎÄ¼þ
Public Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
'¶Á³ö×Ô¶¨ÒåINIÎÄ¼þÖÐµÄµ¥¸öÇø¶Î¼äµÄËùÓÐ¼üÃûºÍÖµ
Public Declare Function GetPrivateProfileSection Lib "kernel32" Alias "GetPrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
'¶Á³ö×Ô¶¨ÒåINIËùÓÐÇø¶ÎÃû
Public Declare Function GetPrivateProfileSectionNames Lib "kernel32.dll" Alias "GetPrivateProfileSectionNamesA" (ByVal lpszReturnBuffer As String, ByVal nSize As Long, ByVal lpFileName As String) As Long

'*************************************************************************
'**º¯ Êý Ãû£ºGetIni
'**¹¦ÄÜÃèÊö£º´Ó×Ô¶¨ÒåiniÎÄ¼þÖÐ¶ÁÐÅÏ¢ SectionName:Çø¶ÎÃû KeyWord:¾ßÌå¼üÃû DefString:¶ÁÈ¡Ê§°Üºó·µ»ØÄ¬ÈÏ FileName:iniÎÄ¼þËùÔÚÂ·¾¶
'**²¹    ³ä£º¶Á³öµÄ¶¼ÊÇStringÀàÐÍµÄ,Èç¹ûÄãÏë¶ÁÊý×ÖÐÍµÄ,¿ÉÓÃVBµÄval()º¯Êý½«Æä×ª»¯
'*************************************************************************
Public Function GetIni(ByVal SectionName As String, ByVal KeyWord As String, ByVal DefString As String, ByVal fileName As String) As String
    Dim ResultString As String * 255
    If GetPrivateProfileString(ByVal SectionName, ByVal KeyWord, vbNullString, ByVal ResultString, ByVal Len(ResultString), ByVal fileName) > 0 Then '¹Ø¼ü´ÊµÄÖµ²»Îª¿Õ
        GetIni = Left(ResultString, InStr(ResultString, Chr(0)) - 1)
    Else    '½«È±Ê¡ÖµÐ´ÈëINIÎÄ¼þ
        WritePrivateProfileString SectionName, KeyWord, DefString, fileName
        GetIni = DefString
    End If
End Function

'*************************************************************************
'**º¯ Êý Ãû£ºGetKeyWord
'**¹¦ÄÜÃèÊö£º´Ó×Ô¶¨ÒåiniÎÄ¼þÖÐµÃµ½¼üÃûºÍÖµ
'**          SectionName:Çø¶ÎÃû  DefString:Ä¬ÈÏÖµ  FileName:iniÎÄ¼þËùÔÚÂ·¾¶
'**·µ    »Ø£ºÿ¼ü¸öÊý
'*************************************************************************
Public Function GetKeyWord(ByVal SectionName As String, TitleNames() As String, ByVal fileName As String) As Long
    Dim szBuf As String * 255
    '    Dim TitleNames() As String
    Dim length  As Integer

    If GetPrivateProfileSection(ByVal SectionName, ByVal szBuf, Len(szBuf), ByVal fileName) > 0 Then
        'Í¬Ê±»ñÈ¡¼üÃûºÍÖµ
    '        GetKeyWord = Left(szBuf, InStr(szBuf, Chr(0)) - 1)
        length = GetPrivateProfileSection(ByVal SectionName, ByVal szBuf, Len(szBuf), ByVal fileName)
        szBuf = Left(szBuf, length)
        TitleNames = Split(szBuf, vbNullChar)
        GetKeyWord = UBound(TitleNames) - LBound(TitleNames) - 1
    '    Else
    '        WritePrivateProfileString SectionName, DefString, vbNullString, FileName
    ''        GetKeyWord = DefString
    '        GetKeyWord = 0
    End If
End Function

'*************************************************************************
'**º¯ Êý Ãû£ºGetKeyString
'**¹¦ÄÜÃèÊö£º´Ó×Ô¶¨ÒåiniÎÄ¼þÖÐµÃµ½¼üÃû
'**          SectionName:Çø¶ÎÃû  DefString:Ä¬ÈÏÖµ  FileName:iniÎÄ¼þËùÔÚÂ·¾¶
'**²¹    ³ä£ºÿ
'*************************************************************************
Public Function GetKeyString(ByVal SectionName As String, ByVal keyName As String, ByVal fileName As String) As String
    Dim szBuf As String * 255, ResultString As String
    Dim length As Long
    length = GetPrivateProfileString(SectionName, keyName, "", szBuf, 255, fileName)
    GetKeyString = szBuf

End Function


Public Sub StringToByte(ByVal strIn As String, ByRef bytOut() As Byte)
    Dim i As Long
    Dim lngLen As Long
    lngLen = Len(strIn)
    ReDim bytOut(lngLen)
    For i = 0 To lngLen - 1
        bytOut(i) = CByte(Asc(Mid(strIn, i + 1, 1)))
    Next
End Sub


Public Function ByteToString(ByRef bytIn() As Byte) As String
    Dim i As Long
    Dim strRet As String
    strRet = ""
    For i = 0 To UBound(bytIn) - 1
        strRet = strRet & Chr(bytIn(i))
    Next
    ByteToString = strRet
End Function

Public Function getStringCRC8(ByVal stringTemp As String) As Byte
   
    Dim bytarray() As Byte
    Dim stringlen As Integer
    Dim i As Integer
    Dim crc8 As Byte
    
    'È¡µÃ³¤¶È
    stringlen = Len(stringTemp)
    '×ª»»Îª×Ö½Ú
    Call StringToByte(stringTemp, bytarray())
    
    crc8 = 0
    'CRC
    For i = 0 To stringlen
        crc8 = crc8 Xor bytarray(i)
    Next
        
    '×ª»Ø
    getStringCRC8 = crc8

End Function



Public Function Str2double(ByVal strTmp As String) As String
    Dim n As Integer
    Dim bytmp As Byte
    Dim bytarray() As Byte
    Dim byt2db() As Byte
    Str2double = ""
        '×ª»»Îª×Ö½Ú
    Call StringToByte(strTmp, bytarray())
        
    For n = 0 To 6
        bytmp = bytarray(n)
        If (bytmp <= 57 And bytmp >= 48) Or bytmp = 46 Then
            Str2double = Str2double & Chr(bytmp) 'testing
        Else
            Exit For
        End If
    Next
End Function


Public Function getLastParaData(TagStr As String, findStr As String) As Double

    Dim tmp As Integer
    Dim n As Integer
    Dim m As Integer
    
    n = Len(TagStr)
    m = Len(findStr)
    tmp = InStrRev(TagStr, findStr)  'checking findstr

    getLastParaData = Val(Right(TagStr, n - (tmp + m - 1)))
    
End Function

Public Function replaceStr(TagStr As String, findStr As String) As String
    Dim i As Integer
    Dim m As Integer
    Dim strTmp As String
    
    m = Len(findStr)
    
    strTmp = ""
    For i = 0 To m
            strTmp = strTmp & "#"
    Next
    
     replaceStr = Replace(TagStr, findStr, strTmp)
     
End Function
