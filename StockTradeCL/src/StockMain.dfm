object StockMainF: TStockMainF
  Left = 0
  Top = 0
  Caption = 'StockMainF'
  ClientHeight = 803
  ClientWidth = 1808
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 784
    Width = 1808
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
        Width = 600
      end
      item
        Alignment = taRightJustify
        Width = 100
      end>
    ExplicitWidth = 1413
  end
  object pnlBgd: TPanel
    Left = 0
    Top = 0
    Width = 1808
    Height = 784
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 1413
    object pnlTop: TPanel
      Left = 1
      Top = 1
      Width = 1806
      Height = 90
      Align = alTop
      TabOrder = 0
      ExplicitWidth = 1411
      object pnlTopMenu: TPanel
        Left = 1
        Top = 42
        Width = 1804
        Height = 47
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 1409
        object btnDebug: TButton
          Left = 8
          Top = 4
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
        object Button2: TButton
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
        end
      end
      object pnlTitle: TPanel
        Left = 1
        Top = 1
        Width = 1804
        Height = 41
        Align = alTop
        TabOrder = 1
        ExplicitWidth = 1409
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
    object KHOpenAPI: TKHOpenAPI
      Left = 896
      Top = 560
      Width = 100
      Height = 33
      TabOrder = 1
      ControlData = {02000100560A00006903000000000000}
    end
    object pnlLeft: TPanel
      Left = 1
      Top = 91
      Width = 216
      Height = 692
      Align = alLeft
      TabOrder = 2
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
          Width = 124
          Height = 21
          Caption = #49324#50857#51088' '#44228#51340' '#51221#48372
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
          Left = 70
          Top = 28
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 0
        end
        object edAccNumber: TEdit
          Left = 70
          Top = 49
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 1
        end
        object edAccCnt: TEdit
          Left = 70
          Top = 70
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 2
        end
        object edBalance: TEdit
          Left = 70
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
        Top = 129
        Width = 214
        Height = 56
        Align = alTop
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
        Top = 185
        Width = 214
        Height = 394
        Align = alClient
        Color = 14540253
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
          Left = 70
          Top = 92
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 0
        end
        object edOrderQuantity: TEdit
          Left = 70
          Top = 71
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 1
        end
        object edOrderCd: TEdit
          Left = 70
          Top = 29
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 2
        end
        object rbUser: TRadioButton
          Left = 8
          Top = 143
          Width = 75
          Height = 17
          Caption = #49324#50857#51088#51648#51221
          TabOrder = 3
        end
        object rbMarket: TRadioButton
          Left = 87
          Top = 143
          Width = 56
          Height = 17
          Caption = #49884#51109#44032
          Checked = True
          TabOrder = 4
          TabStop = True
        end
        object rbCurrent: TRadioButton
          Left = 147
          Top = 143
          Width = 56
          Height = 17
          Caption = #54788#51228#44032
          TabOrder = 5
        end
        object cbTradeType: TComboBox
          Left = 70
          Top = 50
          Width = 121
          Height = 22
          Style = csOwnerDrawFixed
          Color = clSilver
          ItemIndex = 0
          TabOrder = 6
          Text = #49888#44508#47588#49688
          Items.Strings = (
            #49888#44508#47588#49688
            #49888#44508#47588#46020
            #47588#49688#52712#49548
            #47588#46020#52712#49548
            #47588#49688#51221#51221
            #47588#46020#51221#51221)
        end
        object btnTradeInit: TButton
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
          TabOrder = 7
        end
        object btnTradeOk: TButton
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
          TabOrder = 8
        end
        object edOrderNumber: TEdit
          Left = 70
          Top = 113
          Width = 121
          Height = 21
          Color = clSilver
          ReadOnly = True
          TabOrder = 9
        end
      end
      object Panel2: TPanel
        Left = 1
        Top = 579
        Width = 214
        Height = 112
        Align = alBottom
        ParentBackground = False
        TabOrder = 3
        object Label13: TLabel
          Left = 8
          Top = 1
          Width = 69
          Height = 21
          Caption = 'Reserved'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
    end
    object pnlMain: TPanel
      Left = 217
      Top = 91
      Width = 1590
      Height = 692
      Align = alClient
      TabOrder = 3
      ExplicitWidth = 1195
      object Panel3: TPanel
        Left = 683
        Top = 1
        Width = 906
        Height = 690
        Align = alClient
        TabOrder = 0
        ExplicitTop = -3
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
        object sgTradeLog: TStringGrid
          Tag = 1
          Left = 6
          Top = 28
          Width = 892
          Height = 655
          ColCount = 8
          FixedCols = 0
          TabOrder = 0
          OnDrawCell = sgSiglogDrawCell
        end
      end
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 682
        Height = 690
        Align = alLeft
        TabOrder = 1
        ExplicitLeft = 9
        ExplicitTop = 2
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
        object sgSiglog: TStringGrid
          Left = 6
          Top = 28
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
  object tmStatus: TTimer
    Enabled = False
    Interval = 300
    OnTimer = tmStatusTimer
    Left = 880
    Top = 32
  end
end
