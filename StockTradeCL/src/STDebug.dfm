object STDebugF: TSTDebugF
  Left = 0
  Top = 0
  Caption = 'StockTrade-DEBUG'
  ClientHeight = 534
  ClientWidth = 752
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
    Width = 752
    Height = 534
    Align = alClient
    TabOrder = 0
    object pnlTop: TPanel
      Left = 1
      Top = 1
      Width = 750
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
    end
    object pnlLeft: TPanel
      Left = 1
      Top = 65
      Width = 376
      Height = 431
      Align = alLeft
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
      object lbRecvLog: TListBox
        Left = 1
        Top = 33
        Width = 374
        Height = 397
        Align = alBottom
        ItemHeight = 13
        TabOrder = 0
      end
    end
    object pnlRight: TPanel
      Left = 377
      Top = 65
      Width = 374
      Height = 431
      Align = alClient
      TabOrder = 2
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
      object lbSendLog: TListBox
        Left = 1
        Top = 33
        Width = 372
        Height = 397
        Align = alBottom
        ItemHeight = 13
        TabOrder = 0
      end
    end
    object pnlBottom: TPanel
      Left = 1
      Top = 496
      Width = 750
      Height = 37
      Align = alBottom
      TabOrder = 3
    end
  end
end
