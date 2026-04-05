VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "mscomm32.ocx"
Begin VB.Form MainForm 
   Caption         =   "CMD3DP v2.2"
   ClientHeight    =   5820
   ClientLeft      =   3045
   ClientTop       =   3210
   ClientWidth     =   11940
   Icon            =   "frmmaim.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5820
   ScaleWidth      =   11940
   Begin VB.TextBox RedundantCMD 
      Height          =   270
      Left            =   6480
      TabIndex        =   101
      Text            =   "M2 X,M1 X5,M1 X-20"
      Top             =   5520
      Width           =   2055
   End
   Begin VB.CommandButton GenerateCmd 
      Caption         =   "GenerateCMD"
      Height          =   495
      Left            =   8520
      TabIndex        =   100
      Top             =   5280
      Width           =   2055
   End
   Begin VB.Frame Frame16 
      Caption         =   "PrintPara @2"
      Height          =   1095
      Left            =   6480
      TabIndex        =   93
      Top             =   4440
      Width           =   2055
      Begin VB.TextBox PrintParaZdepth 
         Height          =   270
         Left            =   1080
         TabIndex        =   99
         Text            =   "45"
         Top             =   720
         Width           =   615
      End
      Begin VB.TextBox PrintParaYlength 
         Height          =   270
         Left            =   1080
         TabIndex        =   97
         Text            =   "70"
         Top             =   480
         Width           =   615
      End
      Begin VB.TextBox PrintParaYpos 
         Height          =   270
         Left            =   1080
         TabIndex        =   95
         Text            =   "-80"
         Top             =   240
         Width           =   615
      End
      Begin VB.Label Label17 
         Caption         =   "Z-Depth:          mm"
         Height          =   255
         Left            =   120
         TabIndex        =   98
         Top             =   720
         Width           =   1815
      End
      Begin VB.Label Label16 
         Caption         =   "Y-Length:         mm"
         Height          =   255
         Left            =   120
         TabIndex        =   96
         Top             =   480
         Width           =   1815
      End
      Begin VB.Label Label15 
         Caption         =   "Y-Pos Set:        mm"
         Height          =   255
         Left            =   120
         TabIndex        =   94
         Top             =   240
         Width           =   1815
      End
   End
   Begin VB.Frame Frame15 
      Caption         =   "LayerSetPara @1"
      Height          =   1335
      Left            =   4440
      TabIndex        =   83
      Top             =   4440
      Width           =   2055
      Begin VB.TextBox LayerParaRepeat 
         Height          =   270
         Left            =   960
         TabIndex        =   92
         Text            =   "2"
         Top             =   960
         Width           =   495
      End
      Begin VB.TextBox LayerParaUp4Press 
         Height          =   270
         Left            =   960
         TabIndex        =   90
         Text            =   "0.175"
         Top             =   720
         Width           =   735
      End
      Begin VB.TextBox LayerParaPrint 
         Height          =   270
         Left            =   960
         TabIndex        =   88
         Text            =   "1.1"
         Top             =   480
         Width           =   615
      End
      Begin VB.TextBox LayerParaContainer 
         Height          =   270
         Left            =   960
         TabIndex        =   85
         Text            =   "0.8"
         Top             =   240
         Width           =   615
      End
      Begin VB.Label Label14 
         Caption         =   "Repeat:        times"
         Height          =   255
         Left            =   120
         TabIndex        =   91
         Top             =   960
         Width           =   1815
      End
      Begin VB.Label Label13 
         Caption         =   "Up4Press          mm"
         Height          =   255
         Left            =   120
         TabIndex        =   89
         Top             =   720
         Width           =   1815
      End
      Begin VB.Label Label12 
         Caption         =   "Print             mm"
         Height          =   255
         Left            =   120
         TabIndex        =   87
         Top             =   480
         Width           =   1900
      End
      Begin VB.Label Label10 
         Caption         =   "Container         mm"
         Height          =   255
         Left            =   120
         TabIndex        =   84
         Top             =   240
         Width           =   1900
      End
   End
   Begin VB.Frame Frame14 
      Caption         =   "LinePrintPara @3"
      Height          =   855
      Left            =   8520
      TabIndex        =   78
      Top             =   4440
      Width           =   2055
      Begin VB.TextBox LineParaXSpeed 
         Height          =   270
         Left            =   960
         TabIndex        =   82
         Text            =   "100"
         Top             =   480
         Width           =   615
      End
      Begin VB.TextBox LineParaYStep 
         Height          =   270
         Left            =   960
         TabIndex        =   79
         Text            =   "0.65"
         Top             =   240
         Width           =   615
      End
      Begin VB.Label Label9 
         Caption         =   "X-Speed:        cm/s"
         Height          =   255
         Left            =   120
         TabIndex        =   81
         Top             =   480
         Width           =   1815
      End
      Begin VB.Label Label8 
         Caption         =   "Y-Step:          mm"
         Height          =   255
         Left            =   120
         TabIndex        =   80
         Top             =   240
         Width           =   1900
      End
   End
   Begin VB.Frame Frame13 
      Caption         =   "LayerLeft"
      Height          =   735
      Left            =   0
      TabIndex        =   76
      Top             =   3960
      Width           =   1455
      Begin VB.Label lbLayerLeft 
         Alignment       =   2  'Center
         Caption         =   "0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   15.75
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   120
         TabIndex        =   77
         Top             =   240
         Width           =   1095
      End
   End
   Begin VB.Frame Frame12 
      Caption         =   "Temp. [℃]"
      Height          =   765
      Left            =   0
      TabIndex        =   74
      Top             =   4800
      Width           =   1455
      Begin VB.Label YdriverTemp 
         Caption         =   "YdriverTemp"
         Height          =   255
         Left            =   120
         TabIndex        =   102
         Top             =   480
         Width           =   1095
      End
      Begin VB.Label YmotorTemp 
         Caption         =   "Y-Motor:39.00 "
         Height          =   255
         Left            =   120
         TabIndex        =   75
         Top             =   240
         Width           =   1300
      End
   End
   Begin VB.CommandButton cmdBurstManul 
      Caption         =   "Manul"
      Height          =   495
      Left            =   8280
      TabIndex        =   56
      Top             =   3120
      Width           =   735
   End
   Begin VB.Timer cmdTimer 
      Left            =   7440
      Top             =   3480
   End
   Begin VB.CommandButton cmdBurst 
      Caption         =   "BURST"
      Height          =   615
      Left            =   8280
      TabIndex        =   55
      Top             =   3600
      Width           =   735
   End
   Begin VB.TextBox cmdContainer 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   4440
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      Text            =   "frmmaim.frx":6282
      Top             =   3120
      Width           =   3855
   End
   Begin VB.TextBox Text2 
      Height          =   1185
      Left            =   1560
      MultiLine       =   -1  'True
      TabIndex        =   47
      Text            =   "frmmaim.frx":62D7
      Top             =   4440
      Width           =   1740
   End
   Begin VB.CommandButton ClearRecv 
      Caption         =   "CLR"
      Height          =   375
      Left            =   1440
      TabIndex        =   46
      Top             =   3920
      Width           =   495
   End
   Begin VB.CommandButton about 
      Appearance      =   0  'Flat
      Caption         =   "ABT"
      Height          =   280
      Left            =   11160
      TabIndex        =   33
      Top             =   120
      Width           =   600
   End
   Begin VB.CheckBox cmdDelCommentCheck 
      Caption         =   "CMD Cut Comment [;]"
      Height          =   375
      Left            =   9240
      TabIndex        =   36
      Top             =   760
      Value           =   1  'Checked
      Width           =   2175
   End
   Begin VB.CheckBox cmdLineCheck 
      Caption         =   "CMD Line Heading"
      Height          =   375
      Left            =   9240
      TabIndex        =   34
      Top             =   120
      Value           =   1  'Checked
      Width           =   1815
   End
   Begin VB.TextBox posTXT 
      Height          =   350
      Index           =   3
      Left            =   11040
      TabIndex        =   45
      Top             =   2695
      Width           =   495
   End
   Begin VB.TextBox posTXT 
      Height          =   350
      Index           =   2
      Left            =   11040
      TabIndex        =   44
      Top             =   2350
      Width           =   495
   End
   Begin VB.TextBox posTXT 
      Height          =   350
      Index           =   1
      Left            =   11040
      TabIndex        =   43
      Top             =   2015
      Width           =   495
   End
   Begin VB.TextBox posTXT 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0.00;(0.00)"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   2052
         SubFormatType   =   0
      EndProperty
      Height          =   350
      Index           =   0
      Left            =   11040
      TabIndex        =   42
      Top             =   1680
      Width           =   495
   End
   Begin VB.CommandButton posCMD 
      Caption         =   "P"
      Height          =   350
      Index           =   3
      Left            =   10680
      TabIndex        =   41
      Top             =   2695
      Width           =   375
   End
   Begin VB.CommandButton posCMD 
      Caption         =   "C"
      Height          =   350
      Index           =   2
      Left            =   10680
      TabIndex        =   40
      Top             =   2350
      Width           =   375
   End
   Begin VB.CommandButton posCMD 
      Caption         =   "Y"
      Height          =   350
      Index           =   1
      Left            =   10680
      TabIndex        =   39
      Top             =   2015
      Width           =   375
   End
   Begin VB.CommandButton posCMD 
      Caption         =   "X"
      Height          =   350
      Index           =   0
      Left            =   10680
      TabIndex        =   38
      Top             =   1680
      Width           =   375
   End
   Begin VB.CheckBox cmdAddEndingCheck 
      Caption         =   "CMD Add Tail [:]"
      Height          =   375
      Left            =   9240
      TabIndex        =   37
      Top             =   1080
      Value           =   1  'Checked
      Width           =   2175
   End
   Begin VB.CheckBox cmdCRCcheck 
      Caption         =   "CMD CRC Ending [*23]"
      Height          =   375
      Left            =   9240
      TabIndex        =   35
      Top             =   440
      Value           =   1  'Checked
      Width           =   2175
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-8"
      Height          =   375
      Index           =   7
      Left            =   8160
      TabIndex        =   31
      Top             =   2640
      Width           =   855
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-7"
      Height          =   375
      Index           =   6
      Left            =   8160
      TabIndex        =   30
      Top             =   2280
      Width           =   855
   End
   Begin VB.TextBox cmdString 
      BackColor       =   &H80000004&
      Height          =   375
      Index           =   7
      Left            =   4440
      TabIndex        =   29
      Top             =   2640
      Width           =   3735
   End
   Begin VB.TextBox cmdString 
      Height          =   375
      Index           =   6
      Left            =   4440
      TabIndex        =   28
      Top             =   2280
      Width           =   3735
   End
   Begin VB.TextBox cmdString 
      Height          =   375
      Index           =   4
      Left            =   4440
      TabIndex        =   22
      Top             =   1560
      Width           =   3735
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-6"
      Height          =   375
      Index           =   5
      Left            =   8160
      TabIndex        =   27
      Top             =   1920
      Width           =   855
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-5"
      Height          =   375
      Index           =   4
      Left            =   8160
      TabIndex        =   26
      Top             =   1560
      Width           =   855
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-4"
      Height          =   375
      Index           =   3
      Left            =   8160
      TabIndex        =   25
      Top             =   1200
      Width           =   855
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-3"
      Height          =   375
      Index           =   2
      Left            =   8160
      TabIndex        =   24
      Top             =   840
      Width           =   855
   End
   Begin VB.CommandButton cmdButton 
      BackColor       =   &H8000000A&
      Caption         =   "CMD-2"
      Height          =   375
      Index           =   1
      Left            =   8160
      MaskColor       =   &H8000000A&
      TabIndex        =   23
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox cmdString 
      BackColor       =   &H80000004&
      Height          =   390
      Index           =   3
      Left            =   4440
      TabIndex        =   20
      Top             =   1200
      Width           =   3735
   End
   Begin VB.TextBox cmdString 
      Height          =   390
      Index           =   2
      Left            =   4440
      TabIndex        =   19
      Top             =   840
      Width           =   3735
   End
   Begin VB.TextBox cmdString 
      BackColor       =   &H80000004&
      Height          =   390
      Index           =   1
      Left            =   4440
      TabIndex        =   18
      Top             =   480
      Width           =   3735
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "CMD-1"
      Height          =   375
      Index           =   0
      Left            =   8160
      TabIndex        =   17
      Top             =   120
      Width           =   855
   End
   Begin VB.TextBox cmdString 
      Height          =   375
      Index           =   0
      Left            =   4440
      TabIndex        =   16
      Top             =   120
      Width           =   3735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "SND"
      Height          =   375
      Left            =   3840
      TabIndex        =   3
      Top             =   3920
      Width           =   495
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   2520
      Top             =   1200
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.TextBox SendText 
      Height          =   375
      Left            =   1920
      MultiLine       =   -1  'True
      TabIndex        =   2
      Top             =   3920
      Width           =   1935
   End
   Begin VB.TextBox RcvTxt 
      Height          =   3795
      Left            =   1440
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   1
      Top             =   120
      Width           =   2895
   End
   Begin VB.TextBox cmdString 
      BackColor       =   &H80000004&
      Height          =   375
      Index           =   5
      Left            =   4440
      TabIndex        =   21
      Top             =   1920
      Width           =   3735
   End
   Begin VB.Frame Frame5 
      Height          =   4335
      Left            =   1420
      TabIndex        =   32
      Top             =   0
      Width           =   2955
   End
   Begin VB.Frame Frame2 
      Caption         =   "XY-Pos [mm]"
      Height          =   765
      Left            =   0
      TabIndex        =   48
      Top             =   1920
      Width           =   1450
      Begin VB.Label Ypos 
         Caption         =   "Y-POS"
         Height          =   255
         Left            =   240
         TabIndex        =   50
         Top             =   480
         Width           =   975
      End
      Begin VB.Label Xpos 
         Caption         =   "X-POS"
         Height          =   255
         Left            =   240
         TabIndex        =   49
         Top             =   240
         Width           =   1095
      End
   End
   Begin VB.Frame Frame4 
      Height          =   4335
      Left            =   4320
      TabIndex        =   57
      Top             =   0
      Width           =   7575
      Begin VB.CommandButton LastCMD 
         Caption         =   "LST CMD"
         Height          =   495
         Left            =   6800
         TabIndex        =   66
         Top             =   3120
         Width           =   615
      End
      Begin VB.CommandButton cmdHoming 
         Caption         =   "HOME XY"
         Height          =   350
         Left            =   5040
         TabIndex        =   65
         Top             =   2695
         Width           =   855
      End
      Begin VB.CommandButton cmdClrRd 
         Caption         =   "CLR RD "
         Height          =   350
         Left            =   5040
         TabIndex        =   64
         Top             =   2350
         Width           =   855
      End
      Begin VB.CommandButton cmdADJ 
         Caption         =   "ADJ XYZ"
         Height          =   350
         Left            =   5040
         TabIndex        =   63
         Top             =   2015
         Width           =   855
      End
      Begin VB.CommandButton cmdClrNmbrBut 
         Caption         =   "RESET"
         Height          =   465
         Left            =   5880
         TabIndex        =   62
         Top             =   3120
         Width           =   615
      End
      Begin VB.CommandButton cmdSetXY0 
         Caption         =   "XY=0   "
         Height          =   350
         Left            =   5040
         TabIndex        =   61
         Top             =   1680
         Width           =   855
      End
      Begin VB.Frame Frame6 
         Caption         =   "JogMove"
         Height          =   1695
         Left            =   6240
         TabIndex        =   60
         Top             =   1440
         Width           =   1150
      End
      Begin VB.TextBox cmdNmbrTxt 
         Alignment       =   1  'Right Justify
         Height          =   345
         Left            =   5280
         TabIndex        =   59
         Text            =   "1"
         Top             =   3200
         Width           =   615
      End
      Begin VB.Frame Frame9 
         Height          =   3135
         Left            =   0
         TabIndex        =   58
         Top             =   0
         Width           =   4800
         Begin VB.Frame Frame10 
            Caption         =   "Frame10"
            Height          =   15
            Left            =   0
            TabIndex        =   72
            Top             =   3120
            Width           =   4815
         End
      End
      Begin VB.Frame Frame7 
         Caption         =   "CMD"
         Height          =   1695
         Left            =   4920
         TabIndex        =   67
         Top             =   1440
         Width           =   1100
         Begin VB.Frame Frame8 
            Caption         =   "Frame8"
            Height          =   1695
            Left            =   0
            TabIndex        =   68
            Top             =   0
            Width           =   15
         End
      End
      Begin VB.Frame Frame11 
         Height          =   1335
         Left            =   0
         TabIndex        =   73
         Top             =   3000
         Width           =   4800
      End
      Begin VB.Label cmdlbl 
         BackColor       =   &H00C0C0C0&
         Height          =   375
         Left            =   4800
         TabIndex        =   71
         Top             =   3600
         Width           =   2625
      End
      Begin VB.Label Error 
         BackColor       =   &H008080FF&
         Caption         =   " Err:"
         Height          =   240
         Left            =   4800
         TabIndex        =   70
         Top             =   3960
         Width           =   2620
      End
      Begin VB.Label Label1 
         Caption         =   "Next:"
         BeginProperty Font 
            Name            =   "Georgia"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   200
         Left            =   4800
         TabIndex        =   69
         Top             =   3250
         Width           =   495
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Printing"
      Height          =   1125
      Left            =   0
      TabIndex        =   51
      Top             =   2760
      Width           =   1450
      Begin VB.Label LineSpeed 
         Caption         =   "Speed:xxx"
         Height          =   255
         Left            =   100
         TabIndex        =   54
         Top             =   240
         Width           =   1200
      End
      Begin VB.Label LineStep 
         Caption         =   "Step:x.xxmm"
         Height          =   255
         Left            =   200
         TabIndex        =   53
         Top             =   480
         Width           =   1095
      End
      Begin VB.Label LineLeft 
         Caption         =   "Left:xx"
         Height          =   255
         Left            =   200
         TabIndex        =   52
         Top             =   720
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Height          =   1935
      Left            =   0
      TabIndex        =   4
      Top             =   0
      Width           =   1450
      Begin VB.ComboBox Combo5 
         Height          =   300
         ItemData        =   "frmmaim.frx":62F6
         Left            =   600
         List            =   "frmmaim.frx":6300
         TabIndex        =   9
         Text            =   "Combo5"
         Top             =   1080
         Width           =   735
      End
      Begin VB.ComboBox Combo4 
         Height          =   300
         ItemData        =   "frmmaim.frx":630A
         Left            =   600
         List            =   "frmmaim.frx":6317
         TabIndex        =   8
         Text            =   "Combo4"
         Top             =   840
         Width           =   735
      End
      Begin VB.ComboBox Combo3 
         Height          =   300
         ItemData        =   "frmmaim.frx":6324
         Left            =   600
         List            =   "frmmaim.frx":6331
         TabIndex        =   7
         Text            =   "Combo3"
         Top             =   600
         Width           =   735
      End
      Begin VB.ComboBox Combo2 
         Height          =   300
         ItemData        =   "frmmaim.frx":6346
         Left            =   600
         List            =   "frmmaim.frx":636B
         TabIndex        =   6
         Text            =   "Combo2"
         Top             =   360
         Width           =   735
      End
      Begin VB.ComboBox Combo1 
         Height          =   300
         ItemData        =   "frmmaim.frx":63B7
         Left            =   600
         List            =   "frmmaim.frx":63B9
         TabIndex        =   5
         Text            =   "Combo1"
         Top             =   120
         Width           =   735
      End
      Begin VB.CommandButton opencom 
         Caption         =   "OPEN"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   480
         TabIndex        =   10
         Top             =   1440
         Width           =   855
      End
      Begin VB.Shape Shape1 
         FillStyle       =   0  'Solid
         Height          =   255
         Left            =   120
         Shape           =   3  'Circle
         Top             =   1520
         Width           =   375
      End
      Begin VB.Label Label7 
         AutoSize        =   -1  'True
         Caption         =   "STOP"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   15
         Top             =   1080
         Width           =   420
      End
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         Caption         =   "DATA"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   14
         Top             =   840
         Width           =   420
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "CHCK"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   13
         Top             =   600
         Width           =   420
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "BAUD"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   12
         Top             =   360
         Width           =   420
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "COM"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   240
         TabIndex        =   11
         Top             =   120
         Width           =   315
      End
   End
   Begin VB.Label Label11 
      Caption         =   "Container       mm"
      Height          =   255
      Left            =   0
      TabIndex        =   86
      Top             =   0
      Width           =   1815
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'清空RECV-TEXT-BOX
Private Sub ClearRecv_Click()
    RcvTxt.Text = ""
End Sub

Private Sub about_Click()
    MsgBox ("18-April-2015 by CAO,XP @HKUST ")
End Sub



''=======================================================
''=========================系统初始化====================
''=======================================================

Private Sub Form_Load()
    Dim n As Integer
    For n = 1 To 32
        On Error Resume Next
        Err.Clear
        MainForm.MSComm1.CommPort = n                                '这里接收传入的串口号
        MainForm.MSComm1.PortOpen = True
        MainForm.MSComm1.PortOpen = False
        If Err.Number = 0 Then
            Combo1.AddItem ("COM" & n)
        End If
    Next n
    
    If Combo1.ListCount = 0 Then
        MsgBox "COM not found"
    End If

    Combo3.Text = "NULL"
    Combo4.Text = "8"
    Combo5.Text = "1"

    Call initalVariables

    Dim fileName As String
    fileName = App.Path & "\cmdcfg.ini" '        读取ini获取子窗口名称

    Combo2.Text = GetIni("SYS", "baudrate", 1, fileName)              'baudrate
    Combo1.ListIndex = GetIni("SYS", "ComPortNum", 1, fileName) - 1 'com port

    '取得常用命令
    Dim cmdindextemp As String
    For n = 0 To 7
        cmdindextemp = "cmd" & (n + 1)
        cmdString(n).Text = GetKeyString("CMD", cmdindextemp, fileName)
    Next n

    '取得常用XYCP值
    posTXT(0).Text = GetKeyString("CMD", "Xp", fileName)
    posTXT(1).Text = GetKeyString("CMD", "Yp", fileName)
    posTXT(2).Text = GetKeyString("CMD", "Cp", fileName)
    posTXT(3).Text = GetKeyString("CMD", "Pp", fileName)
    
End Sub

''=======================================================
''=====================常用命令发送======================
''=======================================================

'手动发送按钮
Private Sub Command2_Click()
    If MSComm1.PortOpen = True Then
        MSComm1.Output = SendText.Text
    End If
End Sub

'打印机命令发送函数，给定字串即处理命令后发送。
Private Sub sendCMD(ByVal stringTemp As String)

    Dim pos As Integer
    '串口已打开才发送
    If MSComm1.PortOpen = True Then

         '1.查看配置,是否需要截断分号后的注释
        If bCmdDelComment = True Then
            '查找分号
            pos = InStr(1, stringTemp, ";", 1) '文本格式比较
            '截断
                If pos <> 0 Then
                    stringTemp = Left(stringTemp, pos - 1)
                End If
        End If
        
        '1+需不需要把命令前面后面的空格都删掉
        stringTemp = Trim(stringTemp)
        
        If stringTemp <> "" Then
        
    
            '2 如果需要加行号
            If bCmdNmbr = True Then
                stringTemp = "N" & cmdNmbr & " " & stringTemp
            End If
            
            '3如果需要CRC
            If bCmdCRC = True Then
                stringTemp = stringTemp + " *" & getStringCRC8(stringTemp + " ")
            End If
            
            '4.查看配置,是否需要添加行尾标识：
            If bCmdAddEnding = True Then
            stringTemp = stringTemp + ":"
            End If
                    
            '发送字串
            MSComm1.Output = stringTemp
            
            '显示全部的已发送命令，如果有行号及CRC等
            cmdlbl.Caption = stringTemp
            
            '显示行号
            cmdNmbr = cmdNmbr + 1
            cmdNmbrTxt.Text = cmdNmbr
            
        End If  'CHECK EMPTY MSG
        
    '串口是否打开
    End If
End Sub




Private Sub GenerateCmd_Click()

    '@1  SetNewlayer CMD
    cmdString(0).Text = "G0 C" & LayerParaContainer.Text & " P" & LayerParaPrint.Text & " U" & LayerParaUp4Press.Text
    
    '@2 Y-Pos CMD
    cmdString(1).Text = "M1 Y" & PrintParaYpos.Text
    
    '@3 LinePrint CMD
    cmdString(2).Text = "G7 S" & LineParaXSpeed.Text & " Y" & LineParaYStep.Text & " R" & Int(PrintParaYlength.Text / (LineParaYStep * 2) + 0.5)
    
    
    '@4
    cmdString(3).Text = ""
    '@5
    cmdString(4).Text = ""
    '@6
    cmdString(5).Text = ""

    Dim n As Integer
    Dim i As Integer
    Dim cmdStringTemp As String
    Dim layerSetString As String
    
    layerSetString = ""
    n = LayerParaRepeat.Text
    For i = 1 To n
        layerSetString = layerSetString & "@1"
    Next
    
    '汇总每层打印的总命令
    '##代替冗余代码
    layerSetString = layerSetString & "@2##@3" & vbCrLf
    
    '计算需要打印多少层
    Dim zStep As Double
    zStep = (LayerParaPrint.Text - LayerParaUp4Press.Text - LayerParaUp4Press.Text) * LayerParaRepeat.Text
    n = PrintParaZdepth.Text / zStep
    
    
    lbLayerLeft.Caption = n
    
    '生成打印代码
        '首层
    cmdStringTemp = "@1@2##@3" & vbCrLf
        '次层
    For i = 1 To n
        cmdStringTemp = cmdStringTemp & layerSetString
    Next
    
    '尾层盖灰
    cmdStringTemp = cmdStringTemp & "@1@1"
    
    '替换冗余代码
    layerSetString = "," & RedundantCMD.Text & ","
    cmdStringTemp = Replace(cmdStringTemp, "##", layerSetString)
    
    '放入代码池
    cmdContainer.Text = cmdStringTemp
    Call cmdContainer_LostFocus

End Sub

Private Sub LastCMD_Click()
    If MSComm1.PortOpen = True Then
        MSComm1.Output = Trim(cmdlbl.Caption)
    End If
End Sub

Private Sub LayerLeft_Click()

End Sub

Private Sub posTXT_DblClick(Index As Integer)
    posTXT(Index).SelStart = 0
    posTXT(Index).SelLength = Len(posTXT(Index))
End Sub

Private Sub posTXT_KeyDown(Index As Integer, KeyCode As Integer, Shift As Integer)
    Select Case (KeyCode)
        Case vbKeyReturn
                 Call posCMD_Click(Index)
        Case vbKeyUp
                posTXT(Index).Text = posTXT(Index).Text + 1
        Case vbKeyRight
                posTXT(Index).Text = posTXT(Index).Text + 1
        Case vbKeyDown
                posTXT(Index).Text = posTXT(Index).Text - 1
        Case vbKeyLeft
                posTXT(Index).Text = posTXT(Index).Text - 1
    End Select
End Sub

Private Sub posCMD_Click(Index As Integer)

    Dim stringTemp As String
    stringTemp = posTXT(Index).Text
    '有内容才发送
    If Len(stringTemp) <> 0 Then
        stringTemp = "M1 " + posCMD(Index).Caption + stringTemp
        Call sendCMD(stringTemp)
    End If

End Sub

Private Sub cmdADJ_Click()
    Call sendCMD("M0")
End Sub
Private Sub cmdHoming_Click()
    Call sendCMD("M2")
End Sub
Private Sub cmdSetXY0_Click()
    Call sendCMD("M3")
End Sub
Private Sub cmdClrRd_Click()
    Call sendCMD("M4")
End Sub
Private Sub cmdButton_Click(Index As Integer)
    Call sendCMD(cmdString(Index).Text)
End Sub

'=======================================================
'=====================命令参数配置======================
'=======================================================

Private Sub cmdLineCheck_Click()
    If cmdLineCheck.Value Then
        bCmdNmbr = True
    Else
        bCmdNmbr = False
    End If
End Sub
Private Sub cmdCRCcheck_Click()
    If cmdCRCcheck.Value Then
        bCmdCRC = True
    Else
        bCmdCRC = False
    End If
End Sub
Private Sub cmdDelCommentCheck_Click()
    If cmdDelCommentCheck.Value Then
        bCmdDelComment = True
    Else
        bCmdDelComment = False
    End If
End Sub
Private Sub cmdAddEndingCheck_Click()
    If cmdAddEndingCheck.Value Then
        bCmdAddEnding = True
    Else
        bCmdAddEnding = False
    End If
End Sub

Private Sub cmdClrNmbrBut_Click()
    cmdNmbr = 1
    cmdNmbrTxt.Text = cmdNmbr
End Sub

Private Sub cmdNmbrTxt_Change()
    cmdNmbr = cmdNmbrTxt.Text
End Sub
Private Sub cmdNmbrTxt_KeyDown(KeyCode As Integer, Shift As Integer)
    If KeyCode = vbKeyUp Then cmdNmbrTxt.Text = cmdNmbrTxt.Text + 1
    If KeyCode = vbKeyDown Then
        cmdNmbrTxt.Text = cmdNmbrTxt.Text - 1
        If cmdNmbrTxt.Text < 1 Then cmdNmbrTxt.Text = 1
    End If
    cmdNmbr = cmdNmbrTxt.Text
End Sub


''=======================================================
''===================burst命令发送=======================
''=======================================================

Private Sub cmdContainer_DblClick()
    cmdContainer.SelStart = 0
    cmdContainer.SelLength = Len(cmdContainer.Text)
End Sub

'BURST命令预处理，整形排序
Private Sub cmdContainer_LostFocus()
    Dim cmdStrTmp As String
    Dim n As Integer
    
    'Pre order the commands
    cmdStrTmp = cmdContainer.Text & vbCrLf

    '插入冗余代码
    cmdStrTmp = Replace(cmdStrTmp, "#", "," & RedundantCMD.Text & ",")
    
    cmdStrTmp = Replace(cmdStrTmp, vbTab, vbCrLf)
    cmdStrTmp = Replace(cmdStrTmp, ",", vbCrLf)
    cmdStrTmp = Replace(cmdStrTmp, "@@", "@")
    cmdStrTmp = Replace(cmdStrTmp, "@@", "@")
    cmdStrTmp = Replace(cmdStrTmp, "@", vbCrLf & "@")
    cmdStrTmp = Replace(cmdStrTmp, "@" & vbCrLf, vbCrLf)
    
    cmdStrTmp = Replace(cmdStrTmp, vbCrLf & vbCrLf, vbCrLf)
    cmdStrTmp = Replace(cmdStrTmp, vbCrLf & vbCrLf, vbCrLf)
    cmdStrTmp = Replace(cmdStrTmp, vbCrLf & vbCrLf, vbCrLf)
    cmdStrTmp = Replace(cmdStrTmp, vbCrLf & vbCrLf, vbCrLf)
    
    If InStr(cmdStrTmp, vbCrLf) = 1 Then
        cmdStrTmp = Right(cmdStrTmp, Len(cmdStrTmp) - 2)
    End If
    
    'put string back
    cmdContainer.Text = cmdStrTmp
    
    'Calc how many commands
    n = Len(cmdStrTmp)
    cmdStrTmp = Replace(cmdStrTmp, vbCrLf, "")
    cmdBurstLeft = Len(cmdStrTmp)
    cmdBurstLeft = (n - cmdBurstLeft) / Len(vbCrLf)

End Sub


' open BURST MODE
Private Sub cmdBurst_Click()

    If cmdBurst.Caption = "BURST" Then
        cmdTimer.Interval = 400     'milli second
        cmdBurst.Caption = "Begin"
        cmdBurstOK2Send = True
        
        GenerateCmd.Enabled = False
        
    Else
        cmdTimer.Interval = 0
        cmdBurst.Caption = "BURST"
        
        GenerateCmd.Enabled = True
    End If

End Sub

'定时器操作
Private Sub cmdTimer_Timer()

    'Show running
    cmdBurstTimerTick = cmdBurstTimerTick + 1
    If cmdBurstTimerTick = 2 Then
        Select Case Right(cmdBurst.Caption, 3)
                Case "gin"
                    cmdBurst.Caption = cmdBurstLeft & vbCrLf & "<<<"
                 Case "<<<"
                    cmdBurst.Caption = cmdBurstLeft & vbCrLf & "<<-"
                 Case "<<-"
                    cmdBurst.Caption = cmdBurstLeft & vbCrLf & "<--"
                 Case "<--"
                    cmdBurst.Caption = cmdBurstLeft & vbCrLf & "---"
                 Case "---"
                    cmdBurst.Caption = cmdBurstLeft & vbCrLf & "<<<"
        End Select
        cmdBurstTimerTick = 0
    End If
    
    Dim pos As Integer
    Dim strLen As Integer
    Dim cmdTmp As String
    
    If cmdBurstOK2Send = True Then
        Call cmdBurstManul_Click
        cmdBurstOK2Send = False
        cmdBurstTimerTickTimeOut = 0
    Else
        'Ticks counting, in order to check TimerOut
        cmdBurstTimerTickTimeOut = cmdBurstTimerTickTimeOut + 1
        
        If cmdBurstTimerTickTimeOut > 200 Then
            MsgBox ("Warning: Wait ACK Time OUT")
            Call cmdBurst_Click
        End If
        
    End If
    
    If cmdBurstLeft = 0 Then Call cmdBurst_Click

End Sub

Private Sub cmdBurstManul_Click()

    Dim cmdStrTmp As String
    Dim cmdIndex As Integer
    Dim strLen As Long
    Dim pos As Long
    
    'pick one commnad to send
    strLen = Len(cmdContainer.Text)
    pos = InStr(cmdContainer.Text, vbCrLf)
    
    If pos > 1 And cmdBurstLeft > 0 Then
    
        cmdStrTmp = Left(cmdContainer.Text, pos - 1)    'split command and get one
        cmdContainer.Text = Right(cmdContainer.Text, strLen - pos - 1)
        
        'check if @number
        If InStr(cmdStrTmp, "@") = 1 Then
            cmdIndex = 0
            If Len(cmdStrTmp) > 1 Then
                cmdIndex = Mid(cmdStrTmp, 2, 1)
            End If
            If cmdIndex > 0 And cmdIndex < 9 Then
                Call cmdButton_Click(cmdIndex - 1)
            End If
           
        'if not, directly send the command.
        Else
            Call sendCMD(cmdStrTmp)
        End If
        
        'cmd left
        cmdBurstLeft = cmdBurstLeft - 1
        cmdBurst.Caption = cmdBurstLeft & vbCrLf & "---"
        
        If cmdBurstLeft = 0 Then Call cmdBurst_Click
        
    End If

End Sub


Public Sub ProcessCmdAck(ackMsgTmp As String)
    Dim findStr As String
    Dim endStr As String
    Dim tmp As Integer
    Dim n As Integer

    ackMsg = ackMsg & ackMsgTmp

    'Process the message received.
    If Len(ackMsg) > 200 Then
        ackMsg = Right(ackMsg, 200)
    End If
    
    'Find the last line-return
    n = Len(ackMsg)
    tmp = InStrRev(ackMsg, vbCrLf)
    endStr = Right(ackMsg, n - tmp)
    ackMsg = Left(ackMsg, tmp)
       
    
    '===========================
    n = Len(ackMsg)
    
    'Check x,y position
    findStr = "X:"
    If InStrRev(ackMsg, findStr) Then
        Xpos.Caption = "X: " & getLastParaData(ackMsg, findStr)
        ackMsg = replaceStr(ackMsg, findStr)
    End If
    findStr = "Y:"
    If InStrRev(ackMsg, findStr) Then
        Ypos.Caption = "Y: " & getLastParaData(ackMsg, findStr)
        ackMsg = replaceStr(ackMsg, findStr)
    End If
        
    'Checking printing parameters
    findStr = "left:"
    If InStrRev(ackMsg, findStr) Then
        LineLeft.Caption = "Left:" & getLastParaData(ackMsg, findStr)
        ackMsg = replaceStr(ackMsg, findStr)
    End If

        'checking Step
    findStr = "y_mm :"
    If InStrRev(ackMsg, findStr) Then
        LineStep.Caption = "Step:" & getLastParaData(ackMsg, findStr) & "mm"
        ackMsg = replaceStr(ackMsg, findStr)
    End If

        'checking Speed
    findStr = "s_mms:"
    If InStrRev(ackMsg, findStr) Then
        LineSpeed.Caption = "Speed:" & getLastParaData(ackMsg, findStr) & "cm/s"
        ackMsg = replaceStr(ackMsg, findStr)
    End If
            
    'Checking Temperature data
        'checking y motor
    findStr = "YmtrTmp:"
    If InStrRev(ackMsg, findStr) Then
        YmotorTemp.Caption = "Y-Motor:" & getLastParaData(ackMsg, findStr)
        ackMsg = replaceStr(ackMsg, findStr)
    End If
    
        'checking  Y driver
    findStr = "YdvrTmp:"
    If InStrRev(ackMsg, findStr) Then
        YdriverTemp.Caption = "Y-Motor:" & getLastParaData(ackMsg, findStr)
        ackMsg = replaceStr(ackMsg, findStr)
    End If
                                    
     'Check if receive ERROR msg
    findStr = "COM-Err: "
    If InStrRev(ackMsg, findStr) Then
        cmdTimer.Interval = 0
        cmdBurst.Caption = "Error"
        ackMsg = replaceStr(ackMsg, findStr)
    End If

    'receive cmdok    means CMD response
    findStr = "cmdok"
    If InStrRev(ackMsg, findStr) Then
        cmdBurstOK2Send = True      'Burst mode, ok to send next msg
        ackMsg = replaceStr(ackMsg, findStr)
    End If

    'Show many layers left
    findStr = "CMD RCV: LinePrinting"
    If InStrRev(ackMsg, findStr) Then
        tmp = lbLayerLeft.Caption
        tmp = tmp - 1
        If tmp < 0 Then tmp = 0
        lbLayerLeft.Caption = tmp
        ackMsg = replaceStr(ackMsg, findStr)
    End If
    
    'Clear Timeout tick
    cmdBurstTimerTickTimeOut = 0
    
     '=================
     ackMsg = ackMsg & endStr
     
     Text2.Text = ackMsg
     Text2.SelStart = Len(Text2.Text)
            
End Sub





'=======================================================
'=======================串口操作========================
'=======================================================

Private Sub MSComm1_OnComm()
    Dim inputStr As String
    Dim n As Integer
        
    Select Case MSComm1.CommEvent
        Case comEvReceive

            MSComm1.InputMode = 0                    '0：文本方式，1：二进制方式
            inputStr = MSComm1.Input
            
            RcvTxt.Text = RcvTxt.Text + inputStr
            
            '处理长度
            n = Len(RcvTxt.Text)
            If n > 5000 Then
                RcvTxt.Text = Right(RcvTxt.Text, 5000)
                n = InStr(RcvTxt.Text, vbCrLf)
                RcvTxt.Text = Right(RcvTxt.Text, 5000 - n - 1)
            End If

            RcvTxt.SelStart = Len(RcvTxt.Text) '自动滚屏
            
            Call ProcessCmdAck(inputStr)
                                              
    End Select
End Sub

Private Sub opencom_Click()
    Dim comCheck As String
    If opencom.Caption = "CLOSE" Then
        Combo1.Locked = False
        Combo2.Locked = False
        Combo3.Locked = False
        Combo4.Locked = False
        Combo5.Locked = False
        
        MainForm.MSComm1.PortOpen = False
        opencom.Caption = "OPEN"
        MainForm.Shape1.FillColor = RGB(0, 0, 0)


        cmdTimer.Interval = 0
        cmdBurst.Caption = "BURST"

    Else
        If Test_COM(selectComNum) = True Then
            If Combo3.Text = "NULL" Then
                comCheck = "N"
            ElseIf Combo3.Text = "ODD" Then
                comCheck = "O"
            ElseIf Combo3.Text = "EVEN" Then
                comCheck = "E"
            End If
            comSettingStr = Combo2.Text + "," + comCheck + "," + Combo4.Text + "," + Combo5.Text
            initial_com (selectComNum)
            'MainForm.MSComm1.PortOpen = True
            opencom.Caption = "CLOSE"
            MainForm.Shape1.FillColor = RGB(0, 255, 0)
            Combo1.Locked = True
            Combo2.Locked = True
            Combo3.Locked = True
            Combo4.Locked = True
            Combo5.Locked = True
            
            '命令发送参数的初始化
            Call cmdClrNmbrBut_Click '命令数清零
            cmdTimer.Interval = 0
            cmdBurst.Caption = "BURST"
            
        End If
    End If
End Sub

Private Sub Combo1_Click() '选择端口
    selectComNum = Right(Combo1.Text, 1)
    Test_COM (selectComNum)
End Sub

'检测端口号函数'
Public Function Test_COM(com_num As Integer) As Boolean
    On Error Resume Next
    Err.Clear
    MainForm.MSComm1.CommPort = com_num                                '这里接收传入的串口号
    MainForm.MSComm1.PortOpen = True
    MainForm.MSComm1.PortOpen = False
    If Err.Number = 0 Then
        Test_COM = True
    Else
        If Err.Number = 8002 Then
            MsgBox "COM no exist!"
        ElseIf Err.Number = 8005 Then
            MsgBox "COM already OPEN"
        Else
            MsgBox "Error: else"
        End If
        
        Test_COM = False
        
    End If
End Function

'端口初始化子程序'
Public Sub initial_com(com_num As Integer)
    MainForm.MSComm1.CommPort = com_num
    MainForm.MSComm1.OutBufferSize = 1024
    MainForm.MSComm1.InBufferSize = 1024
    MainForm.MSComm1.InputMode = 1
    MainForm.MSComm1.InputLen = 0
    MainForm.MSComm1.InBufferCount = 0
    MainForm.MSComm1.SThreshold = 1
    MainForm.MSComm1.RThreshold = 1
    MainForm.MSComm1.Settings = comSettingStr
    MainForm.MSComm1.PortOpen = True
End Sub

