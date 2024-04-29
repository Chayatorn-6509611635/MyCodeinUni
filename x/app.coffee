app = angular.module('app', [])

app.directive 'calculator', ['PlunkCalculator', (PlunkCalculator) ->
  scope: true
  controller: ['$scope', (s) ->
    changes = 
      perUnit: 'total'
      quantity: 'total'
      total: 'quantity'
    
    s.adjustCalculator = (param, newValue) =>
      @model.adjust changes[param]
      
    s.isMaximumExceeded = => 
      @model.total >= s.maxDaily
      
    s.isNoneConsumed = => 
      @model.isNoItems()
  ]
  link: (s, el, attr, ctrl) ->
    s.data     = s.$eval attr.data
    s.maxDaily = s.$eval attr.maxDaily
    ctrl.model = new PlunkCalculator(data: s.data)
]  

app.factory 'PlunkCalculator', -> 
  class PlunkCalculator
    formulas:
      quantity: (m) -> m.total / m.perUnit
      perUnit:  (m) -> m.total / m.quantity
      total:    (m) -> m.perUnit * m.quantity

    constructor: (args) -> 
      {@data} = args        
      @fillMissing()  
      
    # calculators like to work with numbers, convert on the fly
    # add accessors to the prototype:
    Object.keys(@prototype.formulas).forEach (key) =>
      Object.defineProperty @prototype, key, 
        get: -> 
          +@data[key]
        set: (val) -> 
          # ignore change when not a good number 
          @data[key] = val if val? && !isNaN(parseInt val)   
        
    calc: (param) => 
      @formulas[param](@)
    
    adjust: (param) =>
      @[param] = @calc param
    
    isNoItems: =>
      !(@quantity > 0)
    
    # fill missing parameters from the formulas
    fillMissing: ->
      @adjust(k) for k, v of @data when !v?

app.directive 'userInput', ->
  require: 'ngModel'
  link: (s, el, attr, ngModel) ->
    el.on 'input', -> s.$apply -> 
      s.$eval(attr.userInput)(ngModel.$name, ngModel.$modelValue)

app.directive 'roundTo', ->
  require: 'ngModel'
  link: (s, el, attr, ngModel) ->
    ngModel.$formatters.push (value) -> 
      places = Math.pow(10, +attr.roundTo)
      Math.round(+value * places) / places

app.controller 'AppCtrl', ->
angular.bootstrap document, ['app']