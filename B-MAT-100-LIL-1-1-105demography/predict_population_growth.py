import sys
import csv
import math

def mean(values):
    return sum(values) / len(values)

def covariance(x, y, mean_x, mean_y):
    covar = 0
    for i in range(len(x)):
        covar += (x[i] - mean_x) * (y[i] - mean_y)
    return covar

def variance(values, mean_value):
    return sum((x - mean_value) ** 2 for x in values)

def linear_regression(x, y):
    mean_x = mean(x)
    mean_y = mean(y)
    
    covar = covariance(x, y, mean_x, mean_y)
    var_x = variance(x, mean_x)
    
    slope = covar / var_x
    intercept = mean_y - slope * mean_x
    
    return slope, intercept

def rmse(true_values, predicted_values):
    return math.sqrt(sum((true - pred) ** 2 for true, pred in zip(true_values, predicted_values)) / len(true_values))

def correlation(x, y, mean_x, mean_y):
    return covariance(x, y, mean_x, mean_y) / (math.sqrt(variance(x, mean_x) * variance(y, mean_y)))

def analyze_demography(country_codes):
    if isinstance(country_codes, str):
        country_codes = country_codes.split()
    
    data = []
    all_populations = []
    years = None
    country_names = []
    
    with open('105demography_data.csv', mode='r') as file:
        reader = csv.DictReader(file, delimiter=';')
        for row in reader:
            if row['Country Code'] in country_codes:
                if years is None:
                    years = [int(year) for year in row.keys() if year.isdigit()]
                
                populations = [float(row[str(year)]) / 1000000 for year in years]
                all_populations.append(populations)
                country_names.append(row['Country Name'])

    if not all_populations:
        print(f"No data found for country code {' '.join(country_codes)}.")
        return

    combined_populations = [sum(pop[i] for pop in all_populations) for i in range(len(years))]
    country_names_str = ', '.join(country_names)

    slope_X, intercept_X = linear_regression(years, combined_populations)
    
    population_pred = [slope_X * year + intercept_X for year in years]
    
    rmse_X_value = rmse(combined_populations, population_pred)
    
    population_2050 = slope_X * 2050 + intercept_X
    
    slope_Y, intercept_Y = linear_regression(combined_populations, years)
    
    year_pred = [slope_Y * population + intercept_Y for population in combined_populations]
    
    predicted_populations_fit2 = [(x - intercept_Y) / slope_Y for x in years]
    rmse_Y_value = rmse(combined_populations, predicted_populations_fit2)

    population_2050_fit2 = (2050 - intercept_Y) / slope_Y
    
    mean_x = mean(years)
    mean_y = mean(combined_populations)
    correlation_value = correlation(years, combined_populations, mean_x, mean_y)
    
    print(f"Country: {country_names_str}")
    print("Fit1")
    print(f"    Y = {slope_X:.2f} X {'+' if intercept_X >= 0 else '-'} {abs(intercept_X):.2f}")
    print(f"    Root-mean-square deviation: {rmse_X_value:.2f}")
    print(f"    Population in 2050: {population_2050:.2f}")
    
    print("Fit2")
    print(f"    X = {slope_Y:.2f} Y {'+' if intercept_Y >= 0 else '-'} {abs(intercept_Y):.2f}")
    print(f"    Root-mean-square deviation: {rmse_Y_value:.2f}")
    print(f"    Population in 2050: {population_2050_fit2:.2f}")
    
    print(f"Correlation: {correlation_value:.4f}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 predict_population_growth.py [COUNTRY_CODE ...]")
        sys.exit(84)
    
    country_codes = ' '.join(sys.argv[1:])
    analyze_demography(country_codes)
