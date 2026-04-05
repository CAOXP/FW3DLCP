Attribute VB_Name = "Module1"
Option Explicit

'CXP变量
Public bCmdDelComment As Boolean
Public bCmdAddEnding As Boolean
Public bCmdCRC As Boolean

Public bCmdNmbr As Boolean
Public cmdNmbr As Long

Public cmdBurstOK2Send As Boolean
Public cmdBurstTimerTick As Integer
Public cmdBurstTimerTickTimeOut As Integer
Public cmdBurstLeft As Integer

Public comSettingStr As String          '串口设置参数串
Public selectComNum As Integer        '串口设置参数串


Public Function initalVariables()
    bCmdDelComment = True
    bCmdAddEnding = True
    bCmdCRC = True
    bCmdNmbr = True
End Function


