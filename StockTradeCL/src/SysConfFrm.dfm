object SysConfF: TSysConfF
  Left = 0
  Top = 0
  Caption = #49884#49828#53596#51221#48372' '#49444#51221
  ClientHeight = 120
  ClientWidth = 175
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
    Width = 175
    Height = 120
    Align = alClient
    TabOrder = 0
    object Label9: TLabel
      Left = 8
      Top = 36
      Width = 10
      Height = 13
      Caption = 'IP'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 63
      Width = 22
      Height = 13
      Caption = 'Port'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 1
      Width = 140
      Height = 21
      Caption = #45348#53944#50892#53356' '#51221#48372' '#49444#51221
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object edOrderCd: TEdit
      Left = 38
      Top = 32
      Width = 121
      Height = 21
      Color = clWhite
      TabOrder = 0
    end
    object edPort: TEdit
      Left = 38
      Top = 59
      Width = 121
      Height = 21
      Color = clWhite
      NumbersOnly = True
      TabOrder = 1
    end
    object btnCancel: TButton
      Left = 99
      Top = 86
      Width = 60
      Height = 25
      Caption = #52712#49548
      TabOrder = 2
      OnClick = btnCancelClick
    end
    object btnOk: TButton
      Left = 38
      Top = 86
      Width = 60
      Height = 25
      Caption = #54869#51064
      TabOrder = 3
      OnClick = btnOkClick
    end
  end
end
