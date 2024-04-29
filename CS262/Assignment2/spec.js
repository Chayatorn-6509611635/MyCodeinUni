describe('Protractor Demo App', function(){
    it('should have a title', function(){
        browser.ignoreSynchronization = true;
        browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');
        expect(browser.getTitle()).toEqual('Consumption Calculator');
        browser.sleep(2000);
    });

    it('add 1 cigarettes', async function(){
        await browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');
        await element(by.css('form.ng-scope:nth-child(4) > p:nth-child(1) > input:nth-child(2)')).clear();
        await element(by.css('form.ng-scope:nth-child(4) > p:nth-child(1) > input:nth-child(2)')).sendKeys('1');
        const tar = await element(by.css('form.ng-scope:nth-child(4) > div:nth-child(2) > p:nth-child(2) > input:nth-child(2)')).getAttribute('value');
        await console.log('Tar value: ', tar);
        await expect(tar).toEqual('10');
    });

    it('add 4 cigarettes', async function(){
        await browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');
        await element(by.css('form.ng-scope:nth-child(4) > p:nth-child(1) > input:nth-child(2)')).clear();
        await element(by.css('form.ng-scope:nth-child(4) > p:nth-child(1) > input:nth-child(2)')).sendKeys('4');
        const tar = await element(by.css('form.ng-scope:nth-child(4) > div:nth-child(2) > p:nth-child(2) > input:nth-child(2)')).getAttribute('value');
        await console.log('Tar value: ', tar);
        await expect(tar).toEqual('40');
        
        var warningMessage = await element(by.css('form.ng-scope:nth-child(4) > div:nth-child(2) > p:nth-child(3)'));

        const isWaningShowned = await warningMessage.isDisplayed();
        const warningText =  await warningMessage.getText();
            if (isWaningShowned) {
                console.log("Warning message is shown: ");
            }
        console.log("\"" + warningText + "\"");
    });
});