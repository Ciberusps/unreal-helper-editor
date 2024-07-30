# Unreal Helper Editor [UHE]

UHE - unreal helper editor, editor customization

Support: tested `UE5.4`

## Install

#### From source (recommended):

- `git submodule add https://github.com/Ciberusps/unreal-helper-editor.git ./Plugins/UnrealHelperEditor` - add git submodule to your plugins folder
- add code below to `"<ProjectName>.Build.cs"`

```C#
  public GameName(ReadOnlyTargetRules Target) : base(Target) {
        // ...
        if (Target.bBuildEditor)
        {
           PrivateDependencyModuleNames.AddRange(new string[] { "UnrealHelperEditor" });
        }
        // ...
  }
```

> [!NOTE]
> don't forget to update `README.md` with instructions on how to setup - `git submodule update --init --recursive` and how to update plugin(s) - `git submodule update --remote`

> [!NOTE]
> and add `Editor Preferences -> Force Compilation on Startup` in `Config/EditorPerProjectUserSettings.ini` your team don't want to recompile plugin manually 😉

#### From marketplace:

later sometime

## Update

From source:

- `git submodule update --remote` to update library from source

## Documentation

> - [Custom thumnails](#custom-thumnails)

---

### Custom thumnails

#### `Custom thumnails`

![image](https://github.com/user-attachments/assets/c24fd8bb-0ffe-4666-afd5-8800df650c35)

**Custom thumnails** - to override thumbnail by your own, just implement `IUHECustomThumbnail` interface and define your own icon using `GetCustomThumbnailIcon()`
