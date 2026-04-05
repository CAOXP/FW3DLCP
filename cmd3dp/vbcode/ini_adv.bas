Attribute VB_Name = "ini_adv"
Option Explicit
  
'' INI文件读写Api
Private Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As String, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Private Declare Function GetPrivateProfileSection Lib "kernel32" Alias "GetPrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Private Declare Function GetPrivateProfileSectionNames Lib "kernel32" Alias "GetPrivateProfileSectionNamesA" (ByVal lpszReturnBuffer As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Private Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
Private Declare Function WritePrivateProfileSection Lib "kernel32" Alias "WritePrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpString As String, ByVal lpFileName As String) As Long
  
Private m_sFile     As String
Private Const MC_MAXBUFFER  As Long = 8192
  
'' 得到设置Ini文件名
Public Property Get FileName() As String
    FileName = m_sFile
End Property
Public Property Let FileName(ByVal sFile As String)
    m_sFile = sFile
End Property
  
'' 写键字符串
Public Function WriteString(ByVal sSection As String, ByVal sKey As String, ByVal sValue As String) As Boolean
    WriteString = WritePrivateProfileString(sSection, sKey, sValue, m_sFile) <> 0
End Function
  
'' 读键字符串
Public Function GetString(ByVal sSection As String, ByVal sKey As String) As String
Dim sRet    As String * MC_MAXBUFFER
    Call GetPrivateProfileString(sSection, sKey, vbNullString, sRet, MC_MAXBUFFER, m_sFile)
    GetString = StripNulls(sRet)
End Function
  
'' 删除键值
Public Sub DeleteString(ByVal sSection As String, ByVal sKey As String)
    WritePrivateProfileString sSection, sKey, Nothing, m_sFile
End Sub
  
'' 得到所有节
Public Function GetSections() As String()
Dim sBuffer     As String * MC_MAXBUFFER
    Call GetPrivateProfileSectionNames(sBuffer, MC_MAXBUFFER, m_sFile)
    GetSections = Split(StripNulls2(sBuffer), vbNullChar)
End Function
  
'' 得到节内键值集 [string]=[sValue]
Public Function GetSectionStrings(ByVal sSection As String) As String()
Dim sBuffer As String * MC_MAXBUFFER
    Call GetPrivateProfileSection(sSection, sBuffer, MC_MAXBUFFER, m_sFile)
    GetSectionStrings = Split(StripNulls2(sBuffer), vbNullChar)
End Function
  
'' 删除节
Public Sub DeleteSection(ByVal sSection As String)
    WritePrivateProfileString sSection, Nothing, Nothing, m_sFile
End Sub
  
'' 创建节
Public Sub MakeSection(ByVal sSection As String)
    WritePrivateProfileSection sSection, "", m_sFile
End Sub
  
'' 复制节
Public Function CopySection(ByVal sSection As String, ByVal sNewSection As String)
Dim sBuffer As String * MC_MAXBUFFER
    Call GetPrivateProfileSection(sSection, sBuffer, MC_MAXBUFFER, m_sFile)
    WritePrivateProfileSection sNewSection, StripNulls2(sBuffer), m_sFile
End Function
  
'' 移动节
Public Function MoveSection(ByVal sSection As String, ByVal sNewSection As String)
    CopySection sSection, sNewSection
    DeleteSection sSection
End Function
  
  
'
'-------------------------------------------------------------------------------------------------------------------------------------
'
'' 清除字符串中多余的Null
Private Function StripNulls(ByRef sOriginal As String) As String
Dim i As Long
  
    i = InStr(sOriginal, vbNullChar)
    If i > 0 Then
        StripNulls = Left$(sOriginal, i - 1)
    Else
        StripNulls = sOriginal
    End If
  
End Function
  
'' 清除多余的Null(以2个Null为结束)
Private Function StripNulls2(ByRef sOriginal As String) As String
Dim i   As Long
Const C_FINDER      As String = vbNullChar + vbNullChar
  
    i = InStr(sOriginal, C_FINDER)
    If i > 0 Then
        StripNulls2 = Left$(sOriginal, i - 1)
    Else
        StripNulls2 = sOriginal
    End If
      
End Function
