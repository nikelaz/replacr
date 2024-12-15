function Component()
{
}

Component.prototype.createOperations = function()
{
    component.createOperations();
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@\\replacr.exe", "@StartMenuDir@/replacr.lnk","iconPath=@TargetDir@\\replacr.ico");
    }
}