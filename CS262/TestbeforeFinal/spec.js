describe("Coffee Web App", function() {
    it("should have home", async function() {
        // Disable waiting for Angular as the target app might not be an Angular app
        browser.ignoreSynchronization = true;
        
        // Navigate to the target web page
        await browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');
        
        // Get the title of the current page
        const title = await browser.getTitle();
        
        console.log(title);
        // Assert that the title is as expected
        expect(title).toEqual('Consumption Calculator');
    });

    it("should get tar", async function() {
        await browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');
        const secondInput = await element.all(by.css('input[name="quantity"]')).get(1);
        await secondInput.clear();
        await secondInput.sendKeys('2');
        const secondOutput = element.all(by.css('input.total[name="total"]')).get(1);
        const value = await secondOutput.getAttribute('value');
        console.log('tar is ' + value);
        expect(value).toEqual('20');
    });
});