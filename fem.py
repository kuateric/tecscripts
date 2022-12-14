"""1D finite element code for nonlinear elastostatic."""

import matplotlib.pyplot as plt
import numpy as np


def forward(
        length=1.0,
        A=1.0,
        E=1.0,
        max_iter=100,
        no_elements= 1,
        prescribed_displacement=1e-5,
        material_model="Hooke",
        print_details=None,
):
    """Solve forward problem.

    Solve the forward problem of linear elastostatics for a one-dimensional
    truss using the finite element method.

    Args:
        - length: Total length of the truss.
        - A: Constant cross section area of the truss.
        - E: Young's modulus for linear elastic material law.
        - max_iter: Maximum number of Newton-Raphson iterations.
        - no_elements: Number of finite elements for truss discretization.
        - prescribed_displacement: Prescribed displacement on the right side.
        - Material model: 'Hooke', 'St_Venant', 'Neo_Hooke'.
        - print_details: Output different variables, mainly for debugging.

    Returns:
        - output: A dictionary with displacement and stress data.
    """





    """
    TODO:
    Remember to resuse the arguments passed to forward() ...
    """





    if print_details:
        print(f"\n{80 * '-'}\nMaterial model: {material_model}")

    # Number of nodes
    no_nodes = no_elements+1 ### TODO ###

    # Element length
    length_elements = length/no_elements ### TODO ###

    # Topology field of all elements
    t_nodes = np.zeros(shape=(no_elements, 2), dtype=int)
    for element in range(no_elements):
        t_nodes[element, :] = [element, element + 1]

    # Displacement vector
    U = np.zeros(shape=(no_nodes, 1)) ### TODO ###
    U[-1] = prescribed_displacement### TODO ### boundary conditions 

    # B-matrix for linear truss element
    B = [-1/length_elements, 1/length_elements]### TODO ###

    # Incremental displacement update
    delta_u = 1e-7### TODO ###

    iter_newton = 0
    error = 0

    if print_details:
        print(80 * "-")
    for iter_newton in range(max_iter):

        # Stiffness matrix initialization
        K = np.zeros(shape=(no_nodes, no_nodes))### TODO ###

        if material_model == "Hooke":
            # Stiffness matrix assembly
            for element in range(no_elements):
                K[element:element+2, element:element + 2] += B.T * E * A @ B * length_elements ### TODO ###

        elif material_model == "St_Venant":
            # Stiffness matrix assembly
            for element in range(no_elements):
                K = np.zeros(shape=(no_nodes, no_nodes))### TODO ###


        elif material_model == "Neo_Hooke":
            # Stiffness matrix assembly
            for element in range(no_elements):
                K = np.zeros(shape=(no_nodes, no_nodes))### TODO ###

        else:
            raise ValueError("This material model is not implemented yet!")

        # Calculate residual
        R = np.zeros(shape=(no_nodes)) ### TODO ###
        for element in range(no_elements): 
            node_1,node_2 = t_nodes[element]
            #Bu_e = ### TODO ###
            R += B.T * E * A * B@ U[node_1:node_2+1]* length_elements ### TODO: done ###

        # Error is the norm of the residual
        error = np.linalg.norm(R[1:-1])

        if print_details:
            print(f"Iter: {iter_newton:2}, error: {error:.2e}")

        # Convergence test
        if iter_newton != 0 and error <= 1e-8:
            if print_details:
                print(f"{80 * '-'}\nCONVERGED")
            break
        else:
            pass

        # Solve reduced system
        if iter_newton == 0:
            P = np.zeros(shape=(no_nodes, 1))
            P[:, 0] = P[:, 0] - (K[:, -1] * U[-1]).T
            delta_u[1:-1] = np.linalg.solve(a=K[1:-1, 1:-1], b=(P[1:-1]))

        else:
            delta_u[1:-1] = np.linalg.solve(a=K[1:-1, 1:-1], b=-R[1:-1])

        # Update displacement
        U +=  delta_u ### TODO: done ###

        # Maximum number of iteration test
        if iter_newton == max_iter - 1:
            print(
                f"{80 * '-'}\nMAXIMUM NUMBER OF ITERATIONS REACHED"
                f"\n{80 * '-'}"
            )
            raise SystemError("NO CONVERGENCE")

    # Strains and stresses
    strain = np.zeros(shape=(no_nodes, 1))
    stress = np.zeros(shape=(no_nodes, 1))

    for element in range(no_elements):
        node_1,node_2 = t_nodes[element]
        if material_model == "Hooke": 
            strain[element] +=B@ U[node_1:node_2+1] ### TODO:done ###
            stress[element] +=E * B@ U[node_1:node_2+1] ### TODO:done ###   E* strain[element]

        elif material_model == "St_Venant":
            strain[element] = ### TODO ###
            stress[element] = ### TODO ###

        elif material_model == "Neo_Hooke":
            strain[element] = ### TODO ###
            stress[element] = ### TODO ###
        else:
            raise ValueError("This material model is not implemented yet!")

    if print_details:
        print(
            f"{80 * '-'}\nNumber of iterations: {iter_newton + 1:}, "
            f"Final error: {error:.2e}"
        )
        print(f"{80 * '-'}\nDisplacement:")
        print(np.array2string(U, formatter={"float_kind": "{: .2e}".format}))
        print("\nStrain:")
        print(
            np.array2string(strain, formatter={"float_kind": "{: .2e}".format})
        )
        print("\nStress:")
        print(
            np.array2string(stress, formatter={"float_kind": "{: .2e}".format})
        )
        print(f"{80 * '-'}\n")

    output = {"displacement": U, "strain": strain, "stress": stress}
    return output


if __name__ == "__main__":
    displacements = np.linspace(start=0, stop=5e-1, num=100)
    strains = np.zeros_like(displacements)
    stresses = np.zeros_like(displacements)

    for material in ["Hooke"]:#, "St_Venant", "Neo_Hooke"]:
        for i in range(displacements.size):
            youngs_modulus = 5000
            # noise = np.random.normal(
            # 0, youngs_modulus * 0.1, stresses[i].shape)
            # E = E + noise

            out_dict = forward(
                length=100,
                A=1.5,
                E=youngs_modulus,
                max_iter=100,
                no_elements=2,
                prescribed_displacement=displacements[i],
                material_model=material,
            )

            stresses[i] = out_dict["stress"][-2]
            strains[i] = out_dict["strain"][-2]

        plt.plot(strain, stress)

    np.savetxt(fname="stresses.csv", X=stresses)
    np.savetxt(fname="strains.csv", X=strains)

    plt.title("Stress-strain relation for different materials")
    plt.xlabel("Strain")
    plt.ylabel("Stress")
    plt.legend()
    plt.show()
