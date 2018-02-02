object MecaBackF: TMecaBackF
  Left = 0
  Top = 0
  Caption = 'MecaBackF'
  ClientHeight = 463
  ClientWidth = 907
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 327
    Width = 44
    Height = 13
    Caption = #51333#47785#53076#46300
  end
  object Label2: TLabel
    Left = 21
    Top = 131
    Width = 77
    Height = 13
    Caption = #51333#47785#45817#47588#49688#44552#50529
  end
  object Label5: TLabel
    Left = 112
    Top = 131
    Width = 36
    Height = 13
    Caption = #51092#44256' '#49688
  end
  object Label6: TLabel
    Left = 5
    Top = 150
    Width = 11
    Height = 13
    Caption = #45817
  end
  object Label7: TLabel
    Left = 5
    Top = 175
    Width = 11
    Height = 13
    Caption = #50724
  end
  object KHOpenAPI: TKHOpenAPI
    Left = 0
    Top = 423
    Width = 185
    Height = 17
    TabOrder = 0
    OnReceiveTrData = KHOpenAPIReceiveTrData
    OnReceiveChejanData = KHOpenAPIReceiveChejanData
    OnEventConnect = KHOpenAPIEventConnect
    ControlData = {020001001F130000C201000000000000}
  end
  object mmoUserInfo: TMemo
    Left = 0
    Top = 0
    Width = 161
    Height = 126
    TabOrder = 1
  end
  object btnReqStockInfo: TButton
    Left = 103
    Top = 346
    Width = 57
    Height = 25
    Caption = #50836#52397
    TabOrder = 2
    OnClick = btnReqStockInfoClick
  end
  object btnReqAc: TButton
    Left = 846
    Top = 123
    Width = 57
    Height = 25
    Caption = #44228#51340#51092#44256
    TabOrder = 3
    OnClick = btnReqAcClick
  end
  object statusBar: TStatusBar
    Left = 0
    Top = 445
    Width = 907
    Height = 18
    Panels = <
      item
        Width = 150
      end
      item
        Width = 50
      end
      item
        Width = 50
      end
      item
        Width = 50
      end>
    SizeGrip = False
  end
  object mmoAccount: TMemo
    Left = 744
    Top = 0
    Width = 161
    Height = 126
    TabOrder = 5
  end
  object GroupBox1: TGroupBox
    Left = 738
    Top = 147
    Width = 169
    Height = 217
    Caption = #51452#47928
    TabOrder = 6
    object laOrder1: TLabel
      Left = 16
      Top = 22
      Width = 44
      Height = 13
      Caption = #51333#47785#53076#46300
    end
    object laOrder2: TLabel
      Left = 16
      Top = 48
      Width = 44
      Height = 13
      Caption = #47588#47588#44396#48516
    end
    object laOrder3: TLabel
      Left = 16
      Top = 75
      Width = 44
      Height = 13
      Caption = #51452#47928#49688#47049
    end
    object laOrder4: TLabel
      Left = 16
      Top = 106
      Width = 44
      Height = 13
      Caption = #51452#47928#44032#44201
    end
    object laOrder5: TLabel
      Left = 16
      Top = 131
      Width = 44
      Height = 13
      Caption = #44144#47000#44396#48516
    end
    object laOrder6: TLabel
      Left = 16
      Top = 160
      Width = 44
      Height = 13
      Caption = #51452#47928#48264#54840
    end
    object edOrder1: TEdit
      Left = 69
      Top = 17
      Width = 97
      Height = 21
      TabOrder = 0
      OnKeyPress = edOrder1KeyPress
    end
    object edOrder3: TEdit
      Left = 69
      Top = 71
      Width = 97
      Height = 21
      TabOrder = 1
      OnKeyPress = edOrder1KeyPress
    end
    object edOrder4: TEdit
      Left = 69
      Top = 98
      Width = 97
      Height = 21
      TabOrder = 2
      OnKeyPress = edOrder1KeyPress
    end
    object edOrder5: TEdit
      Left = 69
      Top = 125
      Width = 97
      Height = 21
      Enabled = False
      TabOrder = 3
      Text = #51648#51221#44032
    end
    object Edit6: TEdit
      Left = 69
      Top = 152
      Width = 97
      Height = 21
      TabOrder = 4
    end
    object Button1: TButton
      Left = 64
      Top = 189
      Width = 57
      Height = 25
      Caption = #51452#47928
      TabOrder = 5
      OnClick = Button1Click
    end
    object cbOrderType: TComboBox
      Left = 69
      Top = 44
      Width = 96
      Height = 22
      Style = csOwnerDrawFixed
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
  end
  object mmoOrderLog: TMemo
    Left = 163
    Top = 0
    Width = 579
    Height = 126
    TabOrder = 7
  end
  object mmoCheJanLog: TMemo
    Left = 163
    Top = 128
    Width = 579
    Height = 231
    TabOrder = 8
  end
  object mmoStackInfo: TMemo
    Left = 0
    Top = 373
    Width = 905
    Height = 44
    Lines.Strings = (
      '<'#51452#49885#44592#48376#51221#48372'>')
    TabOrder = 9
  end
  object edReqStockInfo: TEdit
    Left = 0
    Top = 346
    Width = 97
    Height = 21
    TabOrder = 10
    OnKeyPress = edOrder1KeyPress
  end
  object edBettingPrice: TEdit
    Left = 21
    Top = 147
    Width = 76
    Height = 21
    TabOrder = 11
    OnKeyPress = edOrder1KeyPress
  end
  object GroupBox2: TGroupBox
    Left = 3
    Top = 196
    Width = 159
    Height = 125
    Caption = #51088#46041#54840#44032
    TabOrder = 12
    object Label3: TLabel
      Left = 15
      Top = 37
      Width = 66
      Height = 13
      Caption = #47588#49688#54840#44032#51312#51221
    end
    object Label4: TLabel
      Left = 15
      Top = 79
      Width = 66
      Height = 13
      Caption = #47588#46020#54840#44032#51312#51221
    end
    object chHogaAdjust: TCheckBox
      Left = 16
      Top = 14
      Width = 97
      Height = 17
      Caption = #54840#44032#51312#51221
      TabOrder = 0
    end
    object chMesuHUpDwon: TCheckBox
      Left = 35
      Top = 56
      Width = 97
      Height = 17
      Caption = 'V'#52404#53356' '#50948#47196
      TabOrder = 1
    end
    object edMesuHModify: TEdit
      Left = 111
      Top = 52
      Width = 42
      Height = 21
      TabOrder = 2
      OnKeyPress = edOrder1KeyPress
    end
    object chMedoHUpDwon: TCheckBox
      Left = 35
      Top = 98
      Width = 97
      Height = 17
      Caption = 'V'#52404#53356' '#50948#47196
      TabOrder = 3
    end
    object edMedoHModify: TEdit
      Left = 112
      Top = 94
      Width = 41
      Height = 21
      TabOrder = 4
      OnKeyPress = edOrder1KeyPress
    end
  end
  object edMesuCNT: TEdit
    Left = 113
    Top = 147
    Width = 34
    Height = 21
    TabOrder = 13
    OnKeyPress = edOrder1KeyPress
  end
  object edBettingPrice2: TEdit
    Left = 21
    Top = 172
    Width = 76
    Height = 21
    TabOrder = 14
    OnKeyPress = edOrder1KeyPress
  end
  object edMesuCNT2: TEdit
    Left = 113
    Top = 172
    Width = 34
    Height = 21
    TabOrder = 15
    OnKeyPress = edOrder1KeyPress
  end
end
