object STDebugF: TSTDebugF
  Left = 0
  Top = 0
  Caption = 'StockTrade-DEBUG'
  ClientHeight = 907
  ClientWidth = 753
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pnlMain: TPanel
    Left = 0
    Top = 0
    Width = 753
    Height = 907
    Align = alClient
    TabOrder = 0
    object pnlTop: TPanel
      Left = 1
      Top = 1
      Width = 751
      Height = 64
      Align = alTop
      TabOrder = 0
      object Label1: TLabel
        Left = 312
        Top = 0
        Width = 118
        Height = 25
        Alignment = taCenter
        Caption = 'DEBUG From'
        Color = 4194304
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object btnEcho: TButton
        Left = 1
        Top = 36
        Width = 75
        Height = 25
        Caption = 'Echo'
        TabOrder = 0
        OnClick = btnEchoClick
      end
      object btnClear: TButton
        Left = 82
        Top = 36
        Width = 75
        Height = 25
        Caption = 'Clear'
        TabOrder = 1
        OnClick = btnClearClick
      end
    end
    object pnlLeft: TPanel
      Left = 1
      Top = 65
      Width = 376
      Height = 407
      Align = alLeft
      TabOrder = 1
      object lbRecvLog: TListBox
        Left = 1
        Top = 42
        Width = 374
        Height = 359
        Align = alTop
        ItemHeight = 13
        TabOrder = 0
      end
      object Panel1: TPanel
        Left = 1
        Top = 1
        Width = 374
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label2: TLabel
          Left = 1
          Top = 6
          Width = 73
          Height = 21
          Alignment = taCenter
          Caption = 'Recv Info'
          Color = 4194304
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
    end
    object pnlRight: TPanel
      Left = 377
      Top = 65
      Width = 375
      Height = 407
      Align = alClient
      TabOrder = 2
      object lbSendLog: TListBox
        Left = 1
        Top = 42
        Width = 373
        Height = 359
        Align = alTop
        ItemHeight = 13
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 1
        Top = 1
        Width = 373
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label3: TLabel
          Left = 1
          Top = 6
          Width = 75
          Height = 21
          Alignment = taCenter
          Caption = 'Send Info'
          Color = 4194304
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
    end
    object pnlBottom: TPanel
      Left = 1
      Top = 869
      Width = 751
      Height = 37
      Align = alBottom
      TabOrder = 3
    end
    object Panel3: TPanel
      Left = 1
      Top = 472
      Width = 751
      Height = 397
      Align = alBottom
      TabOrder = 4
      object mmSysLog: TMemo
        Left = 1
        Top = 1
        Width = 749
        Height = 395
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
end
