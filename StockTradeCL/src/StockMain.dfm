object StockMainF: TStockMainF
  Left = 0
  Top = 0
  Caption = 'StockMainF'
  ClientHeight = 668
  ClientWidth = 1020
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
    Top = 649
    Width = 1020
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
  end
  object pnlMain: TPanel
    Left = 0
    Top = 0
    Width = 1020
    Height = 649
    Align = alClient
    TabOrder = 1
    object pnlTop: TPanel
      Left = 1
      Top = 1
      Width = 1018
      Height = 90
      Align = alTop
      TabOrder = 0
      object pnlTopMenu: TPanel
        Left = 1
        Top = 42
        Width = 1016
        Height = 47
        Align = alClient
        TabOrder = 0
        object btnDebug: TButton
          Left = 8
          Top = 4
          Width = 75
          Height = 37
          Caption = 'Debug'
          TabOrder = 0
          OnClick = btnDebugClick
        end
      end
      object pnlTitle: TPanel
        Left = 1
        Top = 1
        Width = 1016
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label1: TLabel
          Left = 376
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
  end
  object tmStatus: TTimer
    Enabled = False
    Interval = 300
    OnTimer = tmStatusTimer
    Left = 880
    Top = 32
  end
end
