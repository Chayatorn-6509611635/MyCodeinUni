// spec.js
describe('Protractor Demo App', function(){
    it('should have a title', function(){
        //this page is not angular web page. 
        //I must set ignoreSyncronization to be true.
        browser.ignoreSynchronization = true; 
        browser.get('http://juliemr.github.io/protractor-demo');
        expect(browser.getTitle()).toEqual('Super Calculator') ;
        browser.sleep(2000);
    });
     it('test add 3 with 10 using protractor wait-until-condition', function(){
         browser.get('http://juliemr.github.io/protractor-demo');
         element(by.model('first')).sendKeys('3');
         browser.sleep(1000);
         element(by.model('second')).sendKeys('10');
         element(by.id('gobutton')).click();
         // You can define your own expected condition, which is a function that
         // takes no parameter and evaluates to a promise of a boolean.
         var isNumber = function() {
                 return element(by.tagName('h2')).getText().then(function(text) {
                     return !isNaN(text);
                 });
             };
        browser.wait(isNumber,5000,'Calculation Result taking too long to appear in theDOM');

         element(by.tagName('h2')).getText().then(function(text){
             console.log('Result of Expression (3 + 10):' + text);
             expect(text).toEqual('13');
         });
      
     });


     it('test multiply 2 with 50 using async/await', async function(){
         await browser.get('http://juliemr.github.io/protractor-demo');
         await element(by.model('first')).sendKeys('2');
         await element(by.model('second')).sendKeys('50');
         //let selectElm = element(by.css('select[class="span1"]'));  
         //selectElm.all(by.css('option[value="MULTIPLICATION"]')).click();
         let selectElm = await element(by.model('operator'));  
         await selectElm.all(by.css('option[value="MULTIPLICATION"]')).click();

         await element(by.id('gobutton')).click();
         browser.waitForAngularEnabled(true);
         let  elm = element(by.tagName('h2')) ;
         await elm.getText().then(function(text){
             console.log('Result of Expression (2 * 50):' + text);
             expect(text).toEqual('100');
         });
         browser.waitForAngularEnabled(false);

     });


    it('test assert history table', function(){
        browser.ignoreSynchronization = true;
        browser.get('http://juliemr.github.io/protractor-demo');
        element(by.model('first')).sendKeys('2');
        browser.sleep(1000);
        element(by.model('second')).sendKeys('10');
        element(by.id('gobutton')).click();
        browser.sleep(2000);
        let result;
        element.all(by.repeater('result in memory')).count().then(function(c){
            result = c;
            expect(result).toEqual(1);
        });
    });
});