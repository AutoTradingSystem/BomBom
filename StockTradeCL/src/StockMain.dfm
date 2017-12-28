object StockMainF: TStockMainF
  Left = 0
  Top = 0
  Caption = 'StockMainF'
  ClientHeight = 803
  ClientWidth = 1806
  Color = clBtnFace
  Constraints.MaxWidth = 1822
  Constraints.MinWidth = 1822
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 784
    Width = 1806
    Height = 19
    Panels = <
      item
        Text = 'Comm status'
        Width = 100
      end
      item
        Text = '--'
        Width = 50
      end
      item
        Width = 100
      end
      item
        Alignment = taRightJustify
        Width = 100
      end
      item
        Width = 1300
      end
      item
        Alignment = taCenter
        Width = 50
      end>
  end
  object pnlBgd: TPanel
    Left = 0
    Top = 0
    Width = 1806
    Height = 784
    Align = alClient
    TabOrder = 0
    object pnlTop: TPanel
      Left = 1
      Top = 1
      Width = 1804
      Height = 90
      Align = alTop
      TabOrder = 0
      object pnlTopMenu: TPanel
        Left = 1
        Top = 42
        Width = 1802
        Height = 47
        Align = alClient
        TabOrder = 0
        object btnDebug: TButton
          Left = 8
          Top = 5
          Width = 75
          Height = 37
          Caption = 'Debug'
          TabOrder = 0
          OnClick = btnDebugClick
        end
        object btnOutstandingLog: TButton
          Left = 89
          Top = 4
          Width = 114
          Height = 37
          Caption = #48120#52404#44208' '#45236#50669
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object Button1: TButton
          Left = 209
          Top = 4
          Width = 114
          Height = 37
          Caption = #44228#51340#51092#44256'('#49345#49464')'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object btnConf: TButton
          Left = 329
          Top = 4
          Width = 114
          Height = 37
          Caption = #49444#51221
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = btnConfClick
        end
        object btnSaveCsv: TButton
          Left = 449
          Top = 4
          Width = 114
          Height = 37
          Caption = 'Save CSV'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = btnSaveCsvClick
        end
        object Button3: TButton
          Left = 569
          Top = 6
          Width = 75
          Height = 25
          Caption = #44228#51340#51221#48372
          TabOrder = 5
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 680
          Top = 6
          Width = 75
          Height = 25
          Caption = 'MAP TEST'
          TabOrder = 6
          OnClick = Button4Click
        end
        object Edit1: TEdit
          Left = 775
          Top = 6
          Width = 121
          Height = 21
          TabOrder = 7
        end
        object Button5: TButton
          Left = 1019
          Top = 6
          Width = 75
          Height = 25
          Caption = 'total sell'
          TabOrder = 8
          OnClick = Button5Click
        end
      end
      object pnlTitle: TPanel
        Left = 1
        Top = 1
        Width = 1802
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label1: TLabel
          Left = 0
          Top = 5
          Width = 171
          Height = 25
          Alignment = taCenter
          Caption = 'AutoTrading Client'
          Color = 4194304
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
    end
    object pnlLeft: TPanel
      Left = 1
      Top = 91
      Width = 216
      Height = 692
      Align = alLeft
      TabOrder = 1
      object KHOpenAPI: TKHOpenAPI
        Left = 116
        Top = 35
        Width = 100
        Height = 50
        TabOrder = 5
        OnReceiveTrData = KHOpenAPIReceiveTrData
        OnReceiveChejanData = KHOpenAPIReceiveChejanData
        OnEventConnect = KHOpenAPIEventConnect
        ControlData = {02000100560A00002B05000000000000}
      end
      object pnlUserInfo: TPanel
        Left = 1
        Top = 1
        Width = 214
        Height = 128
        Align = alTop
        Color = 14540253
        ParentBackground = False
        TabOrder = 0
        object Label2: TLabel
          Left = 8
          Top = 1
          Width = 86
          Height = 21
          Caption = #49324#50857#51088' '#51221#48372
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 8
          Top = 32
          Width = 34
          Height = 13
          Caption = #51060'   '#47492
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label4: TLabel
          Left = 8
          Top = 53
          Width = 44
          Height = 13
          Caption = #44228#51340#48264#54840
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label5: TLabel
          Left = 8
          Top = 74
          Width = 44
          Height = 13
          Caption = #44228#51340#44228#49688
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 8
          Top = 95
          Width = 34
          Height = 13
          Caption = #51092'   '#50529
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object edUserName: TEdit
          Left = 78
          Top = 28
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 0
        end
        object edAccNumber: TEdit
          Left = 78
          Top = 49
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 1
        end
        object edAccCnt: TEdit
          Left = 78
          Top = 70
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 2
        end
        object edBalance: TEdit
          Left = 78
          Top = 91
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 3
        end
      end
      object pnlSearch: TPanel
        Left = 1
        Top = 297
        Width = 214
        Height = 56
        Align = alTop
        Color = 14540253
        ParentBackground = False
        TabOrder = 1
        object Label7: TLabel
          Left = 8
          Top = 1
          Width = 64
          Height = 21
          Caption = #51333#47785#44160#49353
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object edStocks: TEdit
          Left = 8
          Top = 28
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 0
        end
        object btnStockSearch: TButton
          Left = 133
          Top = 26
          Width = 75
          Height = 25
          Caption = #44160#49353
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
      end
      object Panel1: TPanel
        Left = 1
        Top = 353
        Width = 214
        Height = 215
        Align = alClient
        ParentBackground = False
        TabOrder = 2
        object Label8: TLabel
          Left = 8
          Top = 1
          Width = 70
          Height = 21
          Caption = #49688#46041' '#51452#47928
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 8
          Top = 33
          Width = 44
          Height = 13
          Caption = #51333#47785#53076#46300
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 8
          Top = 54
          Width = 44
          Height = 13
          Caption = #47588#47588#44396#48516
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label11: TLabel
          Left = 8
          Top = 75
          Width = 44
          Height = 13
          Caption = #51452#47928#49688#47049
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label12: TLabel
          Left = 8
          Top = 96
          Width = 44
          Height = 13
          Caption = #51452#47928#44032#44201
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label14: TLabel
          Left = 8
          Top = 117
          Width = 44
          Height = 13
          Caption = #51452#47928#48264#54840
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object edOrderPrice: TEdit
          Left = 78
          Top = 92
          Width = 121
          Height = 21
          Color = clSilver
          TabOrder = 3
        end
        object edOrderQuantity: TEdit
          Left = 78
          Top = 71
          Width = 121
          Height = 21
          Color = clSilver
          TabOrder = 2
        end
        object edOrderCd: TEdit
          Left = 78
          Top = 28
          Width = 121
          Height = 21
          Color = clSilver
          TabOrder = 0
        end
        object rbUser: TRadioButton
          Left = 8
          Top = 143
          Width = 75
          Height = 17
          Caption = #49324#50857#51088#51648#51221
          TabOrder = 7
        end
        object rbMarket: TRadioButton
          Left = 87
          Top = 143
          Width = 56
          Height = 17
          Caption = #49884#51109#44032
          Checked = True
          TabOrder = 8
          TabStop = True
        end
        object rbCurrent: TRadioButton
          Left = 147
          Top = 143
          Width = 56
          Height = 17
          Caption = #54788#51228#44032
          TabOrder = 9
        end
        object cbOrderType: TComboBox
          Left = 78
          Top = 50
          Width = 121
          Height = 22
          Style = csOwnerDrawFixed
          Color = clSilver
          ItemIndex = 0
          TabOrder = 1
          Text = #49888#44508#47588#49688
          Items.Strings = (
            #49888#44508#47588#49688
            #49888#44508#47588#46020
            #47588#49688#52712#49548
            #47588#46020#52712#49548
            #47588#49688#51221#51221
            #47588#46020#51221#51221)
        end
        object btnOrderReset: TButton
          Left = 52
          Top = 178
          Width = 75
          Height = 25
          Caption = #52488#44592#54868
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
        end
        object btnOrder: TButton
          Left = 133
          Top = 178
          Width = 75
          Height = 25
          Caption = #51452#47928
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = btnOrderClick
        end
        object edOrderNumber: TEdit
          Left = 78
          Top = 113
          Width = 121
          Height = 21
          Color = clSilver
          TabOrder = 4
        end
      end
      object Panel2: TPanel
        Left = 1
        Top = 568
        Width = 214
        Height = 123
        Align = alBottom
        Color = 14540253
        ParentBackground = False
        TabOrder = 3
        object Label13: TLabel
          Left = 8
          Top = 1
          Width = 108
          Height = 21
          Caption = 'System Status'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label17: TLabel
          Left = 8
          Top = 26
          Width = 59
          Height = 13
          Caption = #53412#48372#46300' '#48372#50504
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label18: TLabel
          Left = 8
          Top = 45
          Width = 59
          Height = 13
          Caption = #48169#54868#48317' '#49345#53468
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lbKeyBs: TLabel
          Left = 89
          Top = 26
          Width = 49
          Height = 13
          Caption = #51221#49345'/'#54644#51648
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lbFireSe: TLabel
          Left = 89
          Top = 45
          Width = 87
          Height = 13
          Caption = #48120#49444#51221'/'#49444#51221'/'#54644#51648
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object Panel7: TPanel
        Left = 1
        Top = 129
        Width = 214
        Height = 168
        Align = alTop
        TabOrder = 4
        object Label19: TLabel
          Left = 8
          Top = 1
          Width = 70
          Height = 21
          Caption = #44228#51340' '#51221#48372
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label20: TLabel
          Left = 8
          Top = 32
          Width = 33
          Height = 13
          Caption = #50696#49688#44552
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label21: TLabel
          Left = 8
          Top = 53
          Width = 55
          Height = 13
          Caption = #50696#49688#44552'(+2)'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label22: TLabel
          Left = 8
          Top = 74
          Width = 55
          Height = 13
          Caption = #52509#47588#51077#44552#50529
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label23: TLabel
          Left = 8
          Top = 95
          Width = 55
          Height = 13
          Caption = #45817#51068#49552#51061#50984
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label24: TLabel
          Left = 8
          Top = 137
          Width = 66
          Height = 13
          Caption = #45572#51201#53804#51088#49552#51061
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label25: TLabel
          Left = 8
          Top = 116
          Width = 55
          Height = 13
          Caption = #45572#51201#49552#51061#50984
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
        object edDeposit: TEdit
          Left = 78
          Top = 28
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 0
        end
        object edDeposit2: TEdit
          Left = 78
          Top = 49
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 1
        end
        object edTotalPurchase: TEdit
          Left = 78
          Top = 70
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 2
        end
        object edDayRate: TEdit
          Left = 78
          Top = 91
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 3
        end
        object edCumulativePrice: TEdit
          Left = 78
          Top = 133
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 5
        end
        object edCumulativeRate: TEdit
          Left = 78
          Top = 112
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 4
        end
      end
    end
    object pnlMain: TPanel
      Left = 217
      Top = 91
      Width = 1588
      Height = 692
      Align = alClient
      TabOrder = 2
      object pnlTradeLog: TPanel
        Left = 681
        Top = 1
        Width = 906
        Height = 690
        Align = alClient
        TabOrder = 0
        object Panel5: TPanel
          Left = 1
          Top = 1
          Width = 904
          Height = 25
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object Label15: TLabel
            Left = 7
            Top = 1
            Width = 109
            Height = 21
            Caption = #47588#49688'/'#47588#46020' '#45236#50669
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = #47569#51008' '#44256#46357
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object Panel6: TPanel
          Left = 1
          Top = 26
          Width = 904
          Height = 663
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 1
          object sgTradeLog: TStringGrid
            Tag = 1
            Left = 6
            Top = 8
            Width = 892
            Height = 655
            ColCount = 8
            FixedCols = 0
            TabOrder = 0
            OnDrawCell = sgSiglogDrawCell
            ColWidths = (
              64
              64
              64
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
        end
      end
      object pnlSigLog: TPanel
        Left = 1
        Top = 1
        Width = 680
        Height = 690
        Align = alLeft
        TabOrder = 1
        object Panel3: TPanel
          Left = 1
          Top = 1
          Width = 678
          Height = 25
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object Label16: TLabel
            Left = 7
            Top = 1
            Width = 124
            Height = 21
            Caption = #49884#44536#45328' '#48156#49373' '#45236#50669
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = #47569#51008' '#44256#46357
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object Panel4: TPanel
          Left = 1
          Top = 26
          Width = 678
          Height = 663
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 1
          object sgSiglog: TStringGrid
            Left = 6
            Top = 8
            Width = 670
            Height = 655
            ColCount = 6
            FixedCols = 0
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goTabs, goThumbTracking, goFixedRowClick]
            TabOrder = 0
            OnDrawCell = sgSiglogDrawCell
            ColWidths = (
              64
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
        end
      end
    end
  end
  object Button2: TButton
    Left = 940
    Top = 49
    Width = 75
    Height = 25
    Caption = 'total buy'
    TabOrder = 2
    OnClick = Button2Click
  end
  object tmStatus: TTimer
    Enabled = False
    Interval = 300
    OnTimer = tmStatusTimer
    Left = 1216
    Top = 40
  end
  object MainMenu1: TMainMenu
    Left = 1144
    Top = 40
    object mn100: TMenuItem
      Caption = #54028#51068
      OnClick = mn100Click
      object mn101: TMenuItem
        Tag = 1
        Caption = #49884#49828#53596' '#49444#51221
        OnClick = mn100Click
      end
      object mn102: TMenuItem
        Tag = 2
        Caption = #47196#44536#51064'/'#47196#44536#50500#50883
        OnClick = mn100Click
      end
      object mn104: TMenuItem
        Tag = 3
        Caption = #51333#47308
        OnClick = mn100Click
      end
    end
  end
end
