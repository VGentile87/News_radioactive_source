#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "TrackingAction.hh"
#include "AnalysisManager.hh"
#include "DetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ActionInitialization::ActionInitialization(DetectorConstruction* detConstruction)
 : G4VUserActionInitialization(),
   //fDetector(detector)
   fDetConstruction(detConstruction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ActionInitialization::~ActionInitialization()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::BuildForMaster() const
{
  // Histo manager
  //HistoManager*  histo = new HistoManager();
  
  // Actions
  SetUserAction(new RunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::Build() const
{
  // Histo manager
  // HistoManager*  histo = new HistoManager();
  
  // Actions
  //
  SetUserAction(new PrimaryGeneratorAction(fDetConstruction));
  
  PrimaryGeneratorAction* fGenAction = new PrimaryGeneratorAction(fDetConstruction);
  
  RunAction* runAction = new RunAction();  
  SetUserAction(runAction);
  
  EventAction* eventAction = new EventAction();
  SetUserAction(eventAction);
  
  SteppingAction* steppingAction = new SteppingAction(fDetConstruction, eventAction,  runAction, fGenAction);
  SetUserAction(steppingAction);

}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
