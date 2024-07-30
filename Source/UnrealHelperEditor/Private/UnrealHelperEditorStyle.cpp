// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealHelperEditorStyle.h"
#include "UnrealHelperEditor.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FUnrealHelperEditorStyle::StyleInstance = nullptr;

void FUnrealHelperEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FUnrealHelperEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FUnrealHelperEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("UnrealHelperEditorStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FUnrealHelperEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("UnrealHelperEditorStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("UnrealHelperEditor")->GetBaseDir() / TEXT("Resources"));

	Style->Set("UnrealHelperEditor.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FUnrealHelperEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FUnrealHelperEditorStyle::Get()
{
	return *StyleInstance;
}
