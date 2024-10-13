exports.config = {
    framework: 'jasmine',
    capabilities:{
        browserName: 'firefox'
    },
    seleniumAddress: 'http://localhost:4444/wd/hub',
    //baseUrl: 'https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/',
    specs: ['spec.js']
};