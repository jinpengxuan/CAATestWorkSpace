// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// IdentityCard.h
// Supplies the list of prerequisite components for framework CAATest2
//
//===================================================================
//
// Usage notes:
//   For every prereq framework FW, use the syntax:
//   AddPrereqComponent ("FW", Public);
//
//===================================================================
//
//  Jan 2016  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
// DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
AddPrereqComponent("System",Protected);
// END WIZARD EDITION ZONE
AddPrereqComponent("ApplicationFrame",Public);
AddPrereqComponent("DraftingInterfaces",Public);
AddPrereqComponent("DialogEngine",Public);

AddPrereqComponent("Dialog",Public);
AddPrereqComponent("ObjectSpecsModeler",Public);
AddPrereqComponent("ObjectModelerBase",Public);