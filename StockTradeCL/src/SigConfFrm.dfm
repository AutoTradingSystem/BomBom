object SigConfF: TSigConfF
  Left = 0
  Top = 0
  Caption = #49884#44536#45328' '#51452#47928' '#49444#51221
  ClientHeight = 243
  ClientWidth = 331
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 331
    Height = 243
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    ExplicitLeft = 40
    ExplicitTop = 32
    ExplicitWidth = 635
    ExplicitHeight = 299
    object Label1: TLabel
      Left = 26
      Top = 54
      Width = 120
      Height = 20
      Caption = #52509' '#47588#49688' '#44032#45733' '#44552#50529
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 26
      Top = 78
      Width = 120
      Height = 20
      Caption = #52572#45824' '#47588#49688' '#51333#47785' '#49688
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 26
      Top = 102
      Width = 100
      Height = 20
      Caption = #47588#49688' '#44032#44201' '#49444#51221
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 26
      Top = 126
      Width = 100
      Height = 20
      Caption = #47588#46020' '#44032#44201' '#49444#51221
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 26
      Top = 150
      Width = 115
      Height = 20
      Caption = #49884#44536#45328' '#50976#54952' '#49884#44036
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 288
      Top = 150
      Width = 27
      Height = 20
      Caption = 'min'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object edOrderablePrice: TEdit
      Left = 162
      Top = 53
      Width = 121
      Height = 21
      NumbersOnly = True
      TabOrder = 0
    end
    object edMaxOrderCnt: TEdit
      Left = 162
      Top = 77
      Width = 121
      Height = 21
      NumbersOnly = True
      TabOrder = 1
    end
    object edSigValidTime: TEdit
      Left = 162
      Top = 149
      Width = 121
      Height = 21
      NumbersOnly = True
      TabOrder = 2
    end
    object cbBuyConf: TComboBox
      Left = 162
      Top = 101
      Width = 121
      Height = 21
      ItemIndex = 0
      TabOrder = 3
      Text = #49884#44536#45328#44032
      Items.Strings = (
        #49884#44536#45328#44032
        #49884#51109#44032
        #54788#51228#44032)
    end
    object cbSellConf: TComboBox
      Left = 162
      Top = 125
      Width = 121
      Height = 21
      ItemIndex = 0
      TabOrder = 4
      Text = #49884#44536#45328#44032
      Items.Strings = (
        #49884#44536#45328#44032
        #49884#51109#44032
        #54788#51228#44032)
    end
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 331
      Height = 41
      Align = alTop
      BevelOuter = bvLowered
      Color = clSilver
      ParentBackground = False
      TabOrder = 5
      ExplicitLeft = 88
      ExplicitTop = 16
      ExplicitWidth = 185
      object Label7: TLabel
        Left = 1
        Top = 5
        Width = 329
        Height = 35
        Align = alBottom
        Alignment = taCenter
        Caption = #49884#44536#45328' '#51452#47928' '#49444#51221
        Color = clSilver
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        ExplicitTop = 4
        ExplicitWidth = 343
      end
    end
    object Panel3: TPanel
      Left = 0
      Top = 202
      Width = 331
      Height = 41
      Align = alBottom
      BevelOuter = bvNone
      Color = 14606046
      ParentBackground = False
      TabOrder = 6
      ExplicitLeft = 80
      ExplicitTop = 200
      ExplicitWidth = 185
      object btnOk: TButton
        Left = 87
        Top = 4
        Width = 75
        Height = 35
        Caption = #54869#51064
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object btnCancel: TButton
        Left = 168
        Top = 4
        Width = 75
        Height = 35
        Caption = #52712#49548
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
    end
  end
end
