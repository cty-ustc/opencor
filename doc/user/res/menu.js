function headerAndContentsMenu(pageName, relativePath) {
    doHeaderAndContentsMenu(pageName, relativePath, 54, 96, 146,
                            { "menuItems": [
                                { "level": 0, "label": "Home", "link": "user/index.html" },
                                { "separator": true },
                                { "level": 0, "label": "How to get started?", "link": "http://tutorial-on-cellml-opencor-and-pmr.readthedocs.org/en/latest/index.html", "directLink": true },
                                { "separator": true },
                                { "level": 0, "label": "What is new?", "link": "user/whatIsNew.html" },
                                { "separator": true },
                                { "level": 0, "label": "User interfaces", "link": "user/userInterfaces/index.html" },
                                { "level": 1, "label": "Command line interface (CLI)", "link": "user/userInterfaces/commandLineInterface.html" },
                                { "level": 1, "label": "Graphical user interface (GUI)", "link": "user/userInterfaces/graphicalUserInterface.html" },
                                { "separator": true },
                                { "level": 0, "label": "Plugins", "link": "user/plugins/index.html" },
                                { "level": 1, "label": "Data Store", "subMenuHeader": true },
                                { "level": 2, "label": "BioSignalMLDataStore", "link": "user/plugins/dataStore/BioSignalMLDataStore.html", "subMenuItem": true },
                                { "level": 2, "label": "CSVDataStore", "link": "user/plugins/dataStore/CSVDataStore.html", "subMenuItem": true },
                                { "level": 1, "label": "Editing", "subMenuHeader": true },
                                { "level": 2, "label": "CellMLAnnotationView", "link": "user/plugins/editing/CellMLAnnotationView.html", "subMenuItem": true },
                                { "level": 2, "label": "CellMLTextView", "link": "user/plugins/editing/CellMLTextView.html", "subMenuItem": true },
                                { "level": 2, "label": "RawCellMLView", "link": "user/plugins/editing/RawCellMLView.html", "subMenuItem": true },
                                { "level": 2, "label": "RawSEDMLView", "link": "user/plugins/editing/RawSEDMLView.html", "subMenuItem": true },
                                { "level": 2, "label": "RawTextView", "link": "user/plugins/editing/RawTextView.html", "subMenuItem": true },
                                { "level": 1, "label": "Miscellaneous", "subMenuHeader": true },
                                { "level": 2, "label": "HelpWindow", "link": "user/plugins/miscellaneous/HelpWindow.html", "subMenuItem": true },
                                { "level": 2, "label": "WebBrowserWindow", "link": "user/plugins/miscellaneous/WebBrowserWindow.html", "subMenuItem": true },
                                { "level": 1, "label": "Organisation", "subMenuHeader": true },
                                { "level": 2, "label": "FileBrowserWindow", "link": "user/plugins/organisation/FileBrowserWindow.html", "subMenuItem": true },
                                { "level": 2, "label": "FileOrganiserWindow", "link": "user/plugins/organisation/FileOrganiserWindow.html", "subMenuItem": true },
                                { "level": 2, "label": "PMRWindow", "link": "user/plugins/organisation/PMRWindow.html", "subMenuItem": true },
                                { "level": 1, "label": "Simulation", "subMenuHeader": true },
                                { "level": 2, "label": "SingleCellView", "link": "user/plugins/simulation/SingleCellView.html", "subMenuItem": true },
                                { "level": 1, "label": "Solver", "subMenuHeader": true },
                                { "level": 2, "label": "CVODESolver", "link": "user/plugins/solver/CVODESolver.html", "subMenuItem": true },
                                { "level": 2, "label": "ForwardEulerSolver", "link": "user/plugins/solver/ForwardEulerSolver.html", "subMenuItem": true },
                                { "level": 2, "label": "FourthOrderRungeKuttaSolver", "link": "user/plugins/solver/FourthOrderRungeKuttaSolver.html", "subMenuItem": true },
                                { "level": 2, "label": "HeunSolver", "link": "user/plugins/solver/HeunSolver.html", "subMenuItem": true },
                                { "level": 2, "label": "IDASolver", "link": "user/plugins/solver/IDASolver.html", "subMenuItem": true },
                                { "level": 2, "label": "KINSOLSolver", "link": "user/plugins/solver/KINSOLSolver.html", "subMenuItem": true },
                                { "level": 2, "label": "SecondOrderRungeKuttaSolver", "link": "user/plugins/solver/SecondOrderRungeKuttaSolver.html", "subMenuItem": true },
                                { "level": 1, "label": "Tools", "subMenuHeader": true },
                                { "level": 2, "label": "CellMLTools", "link": "user/plugins/tools/CellMLTools.html", "subMenuItem": true },
                                { "separator": true },
                                { "level": 0, "label": "Known limitations", "link": "user/knownLimitations.html" },
                                { "separator": true },
                                { "level": 0, "label": "Supported platforms", "link": "user/supportedPlatforms.html" },
                                { "separator": true },
                                { "level": 0, "label": "Licensing", "link": "user/licensing.html" },
                                { "separator": true },
                                { "level": 0, "label": "Team", "link": "user/team.html" },
                                { "separator": true },
                                { "level": 0, "label": "Published article", "link": "https://dx.doi.org/10.3389/fphys.2015.00026", "directLink": true },
                                { "separator": true },
                                { "level": 0, "label": "Contact us", "link": "user/contactUs.html" },
                              ]
                            });
}
