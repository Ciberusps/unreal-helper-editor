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
> - [TODO Custom class icon](#custom-class-icon)
> - [TODO Custom class icon](#custom-class-icon)

---

### Custom thumnails

![image](https://github.com/user-attachments/assets/c24fd8bb-0ffe-4666-afd5-8800df650c35)

**Custom thumnails** - to override thumbnail by your own, just implement `IUHECustomThumbnail` interface and define your own icon using `GetCustomThumbnailIcon()`

⚠️ for now works only with C++, TODO add support for blueprints

Thanks to [this post](https://forums.unrealengine.com/t/custom-thumbnail-not-display-asset-is-never-loaded/143155/2?u=ciberus) and [this](https://forums.unrealengine.com/t/custom-thumbnail-on-blueprint/337532/3?u=ciberus)


### Custom class icon

[//]: # (![image]&#40;https://github.com/user-attachments/assets/c24fd8bb-0ffe-4666-afd5-8800df650c35&#41;)

**Custom class icon** - to override classes icons on your own, just implement set settings in `UHESettings`

List of default Unreal Engine Editor icons - https://github.com/EpicKiwi/unreal-engine-editor-icons

⚠️ for now works only with C++, TODO add support for blueprints

Thanks to [this post](https://www.quodsoler.com/blog/customize-your-unreal-class-icons) and [this](https://forums.unrealengine.com/t/how-to-load-a-font-uasset-and-use-it-for-fslatefontinfo/1548466/3?u=ciberus)


### Merge textures Ao + Roughness + Metalic

https://github.com/Atulin/ChannelMerger
