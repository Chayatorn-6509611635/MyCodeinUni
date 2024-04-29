(function anonymous(
) {
var app,
  __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; };

app = angular.module('app', []);

app.directive('calculator', [
  'PlunkCalculator', function(PlunkCalculator) {
    return {
      scope: true,
      controller: [
        '$scope', function(s) {
          var changes,
            _this = this;
          changes = {
            perUnit: 'total',
            quantity: 'total',
            total: 'quantity'
          };
          s.adjustCalculator = function(param, newValue) {
            return _this.model.adjust(changes[param]);
          };
          s.isMaximumExceeded = function() {
            return _this.model.total >= s.maxDaily;
          };
          return s.isNoneConsumed = function() {
            return _this.model.isNoItems();
          };
        }
      ],
      link: function(s, el, attr, ctrl) {
        s.data = s.$eval(attr.data);
        s.maxDaily = s.$eval(attr.maxDaily);
        return ctrl.model = new PlunkCalculator({
          data: s.data
        });
      }
    };
  }
]);

app.factory('PlunkCalculator', function() {
  var PlunkCalculator;
  return PlunkCalculator = (function() {
    var _this = this;

    PlunkCalculator.prototype.formulas = {
      quantity: function(m) {
        return m.total / m.perUnit;
      },
      perUnit: function(m) {
        return m.total / m.quantity;
      },
      total: function(m) {
        return m.perUnit * m.quantity;
      }
    };

    function PlunkCalculator(args) {
      this.isNoItems = __bind(this.isNoItems, this);
      this.adjust = __bind(this.adjust, this);
      this.calc = __bind(this.calc, this);
      this.data = args.data;
      this.fillMissing();
    }

    Object.keys(PlunkCalculator.prototype.formulas).forEach(function(key) {
      return Object.defineProperty(PlunkCalculator.prototype, key, {
        get: function() {
          return +this.data[key];
        },
        set: function(val) {
          if ((val != null) && !isNaN(parseInt(val))) {
            return this.data[key] = val;
          }
        }
      });
    });

    PlunkCalculator.prototype.calc = function(param) {
      return this.formulas[param](this);
    };

    PlunkCalculator.prototype.adjust = function(param) {
      return this[param] = this.calc(param);
    };

    PlunkCalculator.prototype.isNoItems = function() {
      return !(this.quantity > 0);
    };

    PlunkCalculator.prototype.fillMissing = function() {
      var k, v, _ref, _results;
      _ref = this.data;
      _results = [];
      for (k in _ref) {
        v = _ref[k];
        if (v == null) {
          _results.push(this.adjust(k));
        }
      }
      return _results;
    };

    return PlunkCalculator;

  }).call(this);
});

app.directive('userInput', function() {
  return {
    require: 'ngModel',
    link: function(s, el, attr, ngModel) {
      return el.on('input', function() {
        return s.$apply(function() {
          return s.$eval(attr.userInput)(ngModel.$name, ngModel.$modelValue);
        });
      });
    }
  };
});

app.directive('roundTo', function() {
  return {
    require: 'ngModel',
    link: function(s, el, attr, ngModel) {
      return ngModel.$formatters.push(function(value) {
        var places;
        places = Math.pow(10, +attr.roundTo);
        return Math.round(+value * places) / places;
      });
    }
  };
});

app.controller('AppCtrl', function() {});

angular.bootstrap(document, ['app']);

//@ sourceMappingURL=data:application/json;base64,ewogICJ2ZXJzaW9uIjogMywKICAiZmlsZSI6ICIiLAogICJzb3VyY2VSb290IjogIiIsCiAgInNvdXJjZXMiOiBbCiAgICAiaHR0cHM6Ly93d3cuZ2xvYmFsc3FhLmNvbS9hbmd1bGFySnMtcHJvdHJhY3Rvci9Db25zdW1wdGlvbkNhbGN1bGF0b3IvYXBwLmNvZmZlZSIKICBdLAogICJuYW1lcyI6IFtdLAogICJtYXBwaW5ncyI6ICI7QUFBQSxHQUFBLENBQUE7R0FBQSwrRUFBQTs7QUFBQSxDQUFBLENBQTRCLENBQTVCLEVBQU0sQ0FBQSxDQUFPOztBQUViLENBRkEsQ0FFNEIsQ0FBekIsTUFBSCxHQUFBO0VBQWdELENBQW5CLE1BQW9CLE1BQUQsRUFBcEI7V0FDMUI7Q0FBQSxDQUFPLEVBQVAsQ0FBQSxDQUFBO0NBQUEsQ0FDWSxJQUFaLElBQUE7Q0FBdUIsQ0FBQSxDQUFBLEtBQVgsQ0FBQztDQUNYLE1BQUEsT0FBQTtZQUFBLENBQUE7Q0FBQSxFQUNFLElBREYsR0FBQTtDQUNFLENBQVMsS0FBVCxLQUFBO0NBQUEsQ0FDVSxLQURWLENBQ0EsSUFBQTtDQURBLENBRU8sR0FBUCxLQUZBLEVBRUE7Q0FIRixXQUFBO0NBQUEsQ0FLNkIsQ0FBUixFQUFBLEdBQUEsQ0FBQyxDQUF0QixNQUFBO0NBQ0csSUFBQSxDQUFELENBQXNCLFlBQXRCO0NBTkYsVUFLcUI7Q0FMckIsRUFRc0IsTUFBQSxDQUF0QixPQUFBO0NBQ0csR0FBZSxDQUFmLGNBQUQ7Q0FURixVQVFzQjtDQUdyQixFQUFrQixNQUFBLEtBQW5CLEdBQUE7Q0FDRyxJQUFBLElBQUQsVUFBQTtDQWJtQixVQVlGO0NBWlQsUUFBVztRQUR2QjtDQUFBLENBZ0JNLENBQUEsQ0FBTixFQUFBLEdBQU87Q0FDTCxFQUFhLENBQWIsQ0FBYSxHQUFiO0NBQUEsRUFDYSxDQUFZLENBQVosR0FBYjtDQUNLLEVBQVksQ0FBYixDQUFKLFVBQUE7Q0FBaUMsQ0FBTSxFQUFOLE1BQUE7Q0FIN0IsU0FHYTtDQW5CbkIsTUFnQk07Q0FqQndDO0NBQXBCLEVBQW9CO0NBRmhELENBRUE7O0FBdUJBLENBekJBLENBeUIrQixDQUE1QixJQUFILEVBQStCLFFBQS9CO0NBQ0UsS0FBQSxTQUFBO1NBQU07Q0FDSixPQUFBLElBQUE7O0NBQUEsRUFDRSxLQURGO0NBQ0UsQ0FBVSxDQUFBLEdBQVYsRUFBQSxDQUFXO0NBQU8sRUFBUyxFQUFWLFVBQUE7Q0FBakIsTUFBVTtDQUFWLENBQ1UsQ0FBQSxHQUFWLENBQUEsRUFBVztDQUFPLEVBQVMsRUFBVixVQUFBO0NBRGpCLE1BQ1U7Q0FEVixDQUVVLENBQUEsRUFBVixDQUFBLEdBQVc7Q0FBTyxFQUFXLElBQVosUUFBQTtDQUZqQixNQUVVO0NBSFosS0FBQTs7Q0FLYSxFQUFBLENBQUEscUJBQUM7Q0FDWiw0Q0FBQTtDQUFBLHNDQUFBO0NBQUEsa0NBQUE7Q0FBQSxFQUFVLENBQVIsRUFBRDtDQUFELEdBQ0MsRUFBRCxLQUFBO0NBUEYsSUFLYTs7Q0FMYixFQVd5QyxDQUF6QyxFQUFNLENBQU4sQ0FBQSxDQUFzQixNQUFUO0NBQ0osQ0FBMkIsQ0FBbEMsR0FBTSxHQUFOLElBQUEsQ0FBQSxDQUF1QjtDQUNyQixDQUFLLENBQUwsS0FBQSxDQUFLO0FBQ0YsQ0FBRCxFQUFPLENBQUwsYUFBRjtDQURGLFFBQUs7Q0FBTCxDQUVLLENBQUwsS0FBQSxDQUFNO0FBRXlCLENBQTdCLEVBQW1DLENBQWYsQ0FBUyxHQUFNLEVBQW5DLEdBQW9CO0NBQW5CLEVBQUssQ0FBTCxlQUFEO1lBRkc7Q0FGTCxRQUVLO0NBSmdDLE9BQ3ZDO0NBREYsSUFBeUM7O0NBWHpDLEVBbUJNLENBQU4sQ0FBTSxJQUFDO0NBQ0osR0FBQSxDQUFTLEdBQUEsS0FBVjtDQXBCRixJQW1CTTs7Q0FuQk4sRUFzQlEsRUFBQSxDQUFSLEdBQVM7Q0FDTCxFQUFTLENBQVQsQ0FBQSxRQUFGO0NBdkJGLElBc0JROztDQXRCUixFQXlCVyxNQUFYO0FBQ0csQ0FBRCxFQUFjLENBQVgsSUFBRCxLQUFGO0NBMUJGLElBeUJXOztDQXpCWCxFQTZCYSxNQUFBLEVBQWI7Q0FDRSxTQUFBLFVBQUE7Q0FBQTtDQUFBO1NBQUEsR0FBQTtxQkFBQTtJQUFtQztDQUFuQyxHQUFDLEVBQUQ7VUFBQTtDQUFBO3VCQURXO0NBN0JiLElBNkJhOztDQTdCYjs7Q0FGMkI7Q0FBQTs7QUFrQy9CLENBM0RBLENBMkQyQixDQUF4QixNQUFILEVBQUE7U0FDRTtDQUFBLENBQVMsRUFBVCxHQUFBLEVBQUE7Q0FBQSxDQUNNLENBQUEsQ0FBTixHQUFNLEVBQUM7Q0FDRixDQUFELENBQWEsSUFBZixFQUFlLElBQWY7Q0FBbUIsRUFBUSxHQUFULEdBQVMsTUFBVDtDQUNmLENBQXNDLEVBQTNCLENBQVosRUFBK0IsRUFBL0IsRUFBQSxNQUFBO0NBRGdCLFFBQVM7Q0FBM0IsTUFBZTtDQUZqQixJQUNNO0NBRm1CO0NBQUE7O0FBTTNCLENBakVBLENBaUV5QixDQUF0QixNQUFIO1NBQ0U7Q0FBQSxDQUFTLEVBQVQsR0FBQSxFQUFBO0NBQUEsQ0FDTSxDQUFBLENBQU4sR0FBTSxFQUFDO0NBQ0csRUFBaUIsQ0FBekIsQ0FBeUIsRUFBbEIsRUFBbUIsRUFBUCxFQUFuQjtDQUNFLEtBQUEsTUFBQTtBQUF1QixDQUF2QixDQUFTLENBQUEsQ0FBSSxFQUFiLENBQVMsQ0FBVDtBQUNZLENBQVAsRUFBZSxDQUFoQixDQUFKLENBQUEsU0FBQTtDQUZGLE1BQXlCO0NBRjNCLElBQ007Q0FGaUI7Q0FBQTs7QUFPekIsQ0F4RUEsQ0F3RTBCLENBQXZCLE1BQUgsQ0FBQTs7QUFDQSxDQXpFQSxDQXlFNEIsR0FBQSxFQUFyQixDQUFQLENBQUEiLAogICJzb3VyY2VzQ29udGVudCI6IFsKICAgICJhcHAgPSBhbmd1bGFyLm1vZHVsZSgnYXBwJywgW10pXG5cbmFwcC5kaXJlY3RpdmUgJ2NhbGN1bGF0b3InLCBbJ1BsdW5rQ2FsY3VsYXRvcicsIChQbHVua0NhbGN1bGF0b3IpIC0+XG4gIHNjb3BlOiB0cnVlXG4gIGNvbnRyb2xsZXI6IFsnJHNjb3BlJywgKHMpIC0+XG4gICAgY2hhbmdlcyA9IFxuICAgICAgcGVyVW5pdDogJ3RvdGFsJ1xuICAgICAgcXVhbnRpdHk6ICd0b3RhbCdcbiAgICAgIHRvdGFsOiAncXVhbnRpdHknXG4gICAgXG4gICAgcy5hZGp1c3RDYWxjdWxhdG9yID0gKHBhcmFtLCBuZXdWYWx1ZSkgPT5cbiAgICAgIEBtb2RlbC5hZGp1c3QgY2hhbmdlc1twYXJhbV1cbiAgICAgIFxuICAgIHMuaXNNYXhpbXVtRXhjZWVkZWQgPSA9PiBcbiAgICAgIEBtb2RlbC50b3RhbCA+PSBzLm1heERhaWx5XG4gICAgICBcbiAgICBzLmlzTm9uZUNvbnN1bWVkID0gPT4gXG4gICAgICBAbW9kZWwuaXNOb0l0ZW1zKClcbiAgXVxuICBsaW5rOiAocywgZWwsIGF0dHIsIGN0cmwpIC0+XG4gICAgcy5kYXRhICAgICA9IHMuJGV2YWwgYXR0ci5kYXRhXG4gICAgcy5tYXhEYWlseSA9IHMuJGV2YWwgYXR0ci5tYXhEYWlseVxuICAgIGN0cmwubW9kZWwgPSBuZXcgUGx1bmtDYWxjdWxhdG9yKGRhdGE6IHMuZGF0YSlcbl0gIFxuXG5hcHAuZmFjdG9yeSAnUGx1bmtDYWxjdWxhdG9yJywgLT4gXG4gIGNsYXNzIFBsdW5rQ2FsY3VsYXRvclxuICAgIGZvcm11bGFzOlxuICAgICAgcXVhbnRpdHk6IChtKSAtPiBtLnRvdGFsIC8gbS5wZXJVbml0XG4gICAgICBwZXJVbml0OiAgKG0pIC0+IG0udG90YWwgLyBtLnF1YW50aXR5XG4gICAgICB0b3RhbDogICAgKG0pIC0+IG0ucGVyVW5pdCAqIG0ucXVhbnRpdHlcblxuICAgIGNvbnN0cnVjdG9yOiAoYXJncykgLT4gXG4gICAgICB7QGRhdGF9ID0gYXJncyAgICAgICAgXG4gICAgICBAZmlsbE1pc3NpbmcoKSAgXG4gICAgICBcbiAgICAjIGNhbGN1bGF0b3JzIGxpa2UgdG8gd29yayB3aXRoIG51bWJlcnMsIGNvbnZlcnQgb24gdGhlIGZseVxuICAgICMgYWRkIGFjY2Vzc29ycyB0byB0aGUgcHJvdG90eXBlOlxuICAgIE9iamVjdC5rZXlzKEBwcm90b3R5cGUuZm9ybXVsYXMpLmZvckVhY2ggKGtleSkgPT5cbiAgICAgIE9iamVjdC5kZWZpbmVQcm9wZXJ0eSBAcHJvdG90eXBlLCBrZXksIFxuICAgICAgICBnZXQ6IC0+IFxuICAgICAgICAgICtAZGF0YVtrZXldXG4gICAgICAgIHNldDogKHZhbCkgLT4gXG4gICAgICAgICAgIyBpZ25vcmUgY2hhbmdlIHdoZW4gbm90IGEgZ29vZCBudW1iZXIgXG4gICAgICAgICAgQGRhdGFba2V5XSA9IHZhbCBpZiB2YWw/ICYmICFpc05hTihwYXJzZUludCB2YWwpICAgXG4gICAgICAgIFxuICAgIGNhbGM6IChwYXJhbSkgPT4gXG4gICAgICBAZm9ybXVsYXNbcGFyYW1dKEApXG4gICAgXG4gICAgYWRqdXN0OiAocGFyYW0pID0+XG4gICAgICBAW3BhcmFtXSA9IEBjYWxjIHBhcmFtXG4gICAgXG4gICAgaXNOb0l0ZW1zOiA9PlxuICAgICAgIShAcXVhbnRpdHkgPiAwKVxuICAgIFxuICAgICMgZmlsbCBtaXNzaW5nIHBhcmFtZXRlcnMgZnJvbSB0aGUgZm9ybXVsYXNcbiAgICBmaWxsTWlzc2luZzogLT5cbiAgICAgIEBhZGp1c3QoaykgZm9yIGssIHYgb2YgQGRhdGEgd2hlbiAhdj9cblxuYXBwLmRpcmVjdGl2ZSAndXNlcklucHV0JywgLT5cbiAgcmVxdWlyZTogJ25nTW9kZWwnXG4gIGxpbms6IChzLCBlbCwgYXR0ciwgbmdNb2RlbCkgLT5cbiAgICBlbC5vbiAnaW5wdXQnLCAtPiBzLiRhcHBseSAtPiBcbiAgICAgIHMuJGV2YWwoYXR0ci51c2VySW5wdXQpKG5nTW9kZWwuJG5hbWUsIG5nTW9kZWwuJG1vZGVsVmFsdWUpXG5cbmFwcC5kaXJlY3RpdmUgJ3JvdW5kVG8nLCAtPlxuICByZXF1aXJlOiAnbmdNb2RlbCdcbiAgbGluazogKHMsIGVsLCBhdHRyLCBuZ01vZGVsKSAtPlxuICAgIG5nTW9kZWwuJGZvcm1hdHRlcnMucHVzaCAodmFsdWUpIC0+IFxuICAgICAgcGxhY2VzID0gTWF0aC5wb3coMTAsICthdHRyLnJvdW5kVG8pXG4gICAgICBNYXRoLnJvdW5kKCt2YWx1ZSAqIHBsYWNlcykgLyBwbGFjZXNcblxuYXBwLmNvbnRyb2xsZXIgJ0FwcEN0cmwnLCAtPlxuYW5ndWxhci5ib290c3RyYXAgZG9jdW1lbnQsIFsnYXBwJ10iCiAgXQp9
//@ sourceURL=coffeescript
})