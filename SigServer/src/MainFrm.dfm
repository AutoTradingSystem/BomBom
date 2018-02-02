object MainF: TMainF
  Left = 0
  Top = 0
  Caption = 'MainF'
  ClientHeight = 308
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object edMonth: TEdit
    Left = 344
    Top = 43
    Width = 65
    Height = 21
    TabOrder = 0
  end
  object edDay: TEdit
    Left = 344
    Top = 70
    Width = 65
    Height = 21
    TabOrder = 1
  end
  object edHour: TEdit
    Left = 344
    Top = 97
    Width = 65
    Height = 21
    TabOrder = 2
  end
  object edMinute: TEdit
    Left = 344
    Top = 124
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object edCode: TEdit
    Left = 344
    Top = 151
    Width = 65
    Height = 21
    TabOrder = 4
  end
  object cbMark: TComboBox
    Left = 344
    Top = 16
    Width = 65
    Height = 21
    TabOrder = 5
    Text = #44396#48516
    Items.Strings = (
      #47588#49688
      #47588#46020)
  end
  object edName: TEdit
    Left = 344
    Top = 179
    Width = 65
    Height = 21
    TabOrder = 6
  end
  object edPrice: TEdit
    Left = 344
    Top = 208
    Width = 65
    Height = 21
    TabOrder = 7
  end
  object btnSend: TButton
    Left = 344
    Top = 240
    Width = 65
    Height = 25
    Caption = #51204#49569
    TabOrder = 8
    OnClick = btnSendClick
  end
  object Button1: TButton
    Left = 360
    Top = 16
    Width = 73
    Height = 17
    Caption = 'Button1'
    TabOrder = 5
    OnClick = Button1Click
  end
  object tmClock: TTimer
    Enabled = False
    OnTimer = tmClockTimer
    Left = 403
    Top = 95
  end
  object DB: TSQLConnection
    ConnectionName = 'MySQLConnection'
    DriverName = 'MySQL'
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=Data.DBXMySQL'
      
        'DriverPackageLoader=TDBXDynalinkDriverLoader,DbxCommonDriver240.' +
        'bpl'
      
        'DriverAssemblyLoader=Borland.Data.TDBXDynalinkDriverLoader,Borla' +
        'nd.Data.DbxCommonDriver,Version=24.0.0.0,Culture=neutral,PublicK' +
        'eyToken=91d62ebb5b0d1b1b'
      
        'MetaDataPackageLoader=TDBXMySqlMetaDataCommandFactory,DbxMySQLDr' +
        'iver240.bpl'
      
        'MetaDataAssemblyLoader=Borland.Data.TDBXMySqlMetaDataCommandFact' +
        'ory,Borland.Data.DbxMySQLDriver,Version=24.0.0.0,Culture=neutral' +
        ',PublicKeyToken=91d62ebb5b0d1b1b'
      'GetDriverFunc=getSQLDriverMYSQL'
      'LibraryName=dbxmys.dll'
      'LibraryNameOsx=libsqlmys.dylib'
      'VendorLib=LIBMYSQL.dll'
      'VendorLibWin64=libmysql.dll'
      'VendorLibOsx=libmysqlclient.dylib'
      'HostName=ServerName'
      'Database=DBNAME'
      'User_Name=user'
      'Password=password'
      'MaxBlobSize=-1'
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'BlobSize=-1'
      'ErrorResourceFile=')
    Left = 232
    Top = 64
  end
end
